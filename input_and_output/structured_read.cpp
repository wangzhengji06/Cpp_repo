#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// ------------------------------------------------------------
// Error helpers
// ------------------------------------------------------------

void error(const string &s) { throw runtime_error(s); }

void error(const string &s, const string &s2) {
  throw runtime_error(s + ": " + s2);
}

void error(const string &s, int n) {
  throw runtime_error(s + ": " + to_string(n));
}

// ------------------------------------------------------------
// Constants
// ------------------------------------------------------------

constexpr int not_a_month = -1;
constexpr double not_a_reading = -7777;

constexpr int hours_per_day = 24;
constexpr int max_days_per_month = 32; // we waste day[0], use day[1] to day[31]
constexpr int months_per_year = 12;

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

// ------------------------------------------------------------
// Data structures
// ------------------------------------------------------------

// A Reading is only used while reading input.
// It represents one item like:
//     (15 14 -8.8)
// meaning:
//     day = 15, hour = 14, temperature = -8.8
struct Reading {
  int day;
  int hour;
  double temperature;
};

// A Day stores 24 hourly temperatures.
// hour[0] means 00:00, hour[23] means 23:00.
struct Day {
  vector<double> hour = vector<double>(hours_per_day, not_a_reading);
};

// A Month stores days.
// We use day[1] to day[31].
// day[0] is unused to keep indexing simple.
struct Month {
  int month = not_a_month; // [0:11], jan is 0, dec is 11
  vector<Day> day = vector<Day>(max_days_per_month);
};

// A Year stores 12 months.
// month[0] is January, month[11] is December.
struct Year {
  int year;
  vector<Month> month = vector<Month>(months_per_year);
};

// ------------------------------------------------------------
// Month name conversion
// ------------------------------------------------------------

// Input uses short month names.
vector<string> month_input_tbl = {"jan", "feb", "mar", "apr", "may", "jun",
                                  "jul", "aug", "sep", "oct", "nov", "dec"};

// Output uses full month names.
vector<string> month_print_tbl = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};

// Convert "jan" to 0, "feb" to 1, ..., "dec" to 11.
// Return not_a_month if the string is not a valid month name.
int month_to_int(const string &s) {
  for (int i = 0; i < months_per_year; ++i) {
    if (month_input_tbl[i] == s) {
      return i;
    }
  }

  return not_a_month;
}

// Convert 0 to "January", 1 to "February", ..., 11 to "December".
string int_to_month(int i) {
  if (i < 0 || months_per_year <= i) {
    error("bad month index", i);
  }

  return month_print_tbl[i];
}

// ------------------------------------------------------------
// Reading validation
// ------------------------------------------------------------

bool is_valid(const Reading &r) {
  if (r.day < 1 || 31 < r.day) {
    return false;
  }

  if (r.hour < 0 || 23 < r.hour) {
    return false;
  }

  if (r.temperature < implausible_min || implausible_max < r.temperature) {
    return false;
  }

  return true;
}

// ------------------------------------------------------------
// end_of_loop
//
// This function is called after a loop such as:
//
//     for (Reading r; is >> r; ) { ... }
//
// That loop stops when reading a Reading fails.
// That failure may be normal if the next character is '}'.
// So this function checks whether the loop ended correctly.
// ------------------------------------------------------------

void end_of_loop(istream &is, char terminator, const string &message) {
  if (is.fail()) {
    is.clear();

    char ch = 0;
    if (is >> ch && ch == terminator) {
      return; // normal end of loop
    }

    error(message);
  }
}

// ------------------------------------------------------------
// Input operator for Reading
//
// Expected format:
//     ( day hour temperature )
//
// Example:
//     (15 14 -8.8)
// ------------------------------------------------------------

istream &operator>>(istream &is, Reading &r) {
  char ch1 = 0;

  // First check whether this could be a Reading.
  // A Reading must start with '('.
  if (is >> ch1 && ch1 != '(') {
    is.unget();
    is.clear(ios::failbit);
    return is;
  }

  char ch2 = 0;

  // Now read the actual values.
  is >> r.day >> r.hour >> r.temperature >> ch2;

  if (!is) {
    return is;
  }

  // If the reading started with '(' but didn't end with ')',
  // the input format is seriously wrong.
  if (ch2 != ')') {
    error("bad reading");
  }

  return is;
}

// ------------------------------------------------------------
// Input operator for Month
//
// Expected format:
//     { month feb (1 1 68) (2 3 66.66) }
//
// It starts with:
//     { month feb
//
// Then it reads many Readings until it reaches:
//     }
// ------------------------------------------------------------

istream &operator>>(istream &is, Month &m) {
  char ch = 0;

  // A Month must start with '{'.
  // If we don't see '{', this is not a Month.
  if (is >> ch && ch != '{') {
    is.unget();
    is.clear(ios::failbit);
    return is;
  }

  string month_marker;
  string month_name;

  is >> month_marker >> month_name;

  if (!is || month_marker != "month") {
    error("bad start of month");
  }

  int month_number = month_to_int(month_name);

  if (month_number == not_a_month) {
    error("bad month name", month_name);
  }

  m.month = month_number;

  int duplicates = 0;
  int invalids = 0;

  // Read all readings in this month.
  //
  // This loop stops when operator>> for Reading fails.
  // Usually that happens when it sees '}', meaning the month ended.
  for (Reading r; is >> r;) {
    if (is_valid(r)) {
      // Check if we already have a reading for this day/hour.
      if (m.day[r.day].hour[r.hour] != not_a_reading) {
        ++duplicates;
      }

      // Store the temperature in the Month structure.
      m.day[r.day].hour[r.hour] = r.temperature;
    } else {
      ++invalids;
    }
  }

  if (invalids) {
    error("invalid readings in month", invalids);
  }

  if (duplicates) {
    error("duplicate readings in month", duplicates);
  }

  // The Reading loop should have stopped because it saw '}'.
  end_of_loop(is, '}', "bad end of month");

  return is;
}

// ------------------------------------------------------------
// Input operator for Year
//
// Expected format:
//     { year 2000
//         { month feb ... }
//         { month dec ... }
//     }
//
// It starts with:
//     { year 2000
//
// Then it reads many Months until it reaches:
//     }
// ------------------------------------------------------------

istream &operator>>(istream &is, Year &y) {
  char ch = 0;

  is >> ch;

  // A Year must start with '{'.
  // If not, this is not a Year.
  if (ch != '{') {
    is.unget();
    is.clear(ios::failbit);
    return is;
  }

  string year_marker;
  int yy = -1;

  is >> year_marker >> yy;

  if (!is || year_marker != "year") {
    error("bad start of year");
  }

  y.year = yy;

  // Read all months in this year.
  while (true) {
    Month m; // Important: get a fresh Month every time.

    if (!(is >> m)) {
      break;
    }

    y.month[m.month] = m;
  }

  // The Month loop should have stopped because it saw '}'.
  end_of_loop(is, '}', "bad end of year");

  return is;
}

// ------------------------------------------------------------
// Output helper
// ------------------------------------------------------------

void print_year(ostream &os, const Year &y) {
  os << "Year: " << y.year << '\n';

  for (int m = 0; m < months_per_year; ++m) {
    const Month &month = y.month[m];

    if (month.month == not_a_month) {
      continue;
    }

    os << "  Month: " << int_to_month(month.month) << '\n';

    for (int d = 1; d <= 31; ++d) {
      for (int h = 0; h < hours_per_day; ++h) {
        double temp = month.day[d].hour[h];

        if (temp != not_a_reading) {
          os << "    day " << d << ", hour " << h << ", temperature " << temp
             << '\n';
        }
      }
    }
  }
}

// ------------------------------------------------------------
// main
// ------------------------------------------------------------

int main() {
  try {
    // Open input file.
    cout << "Please enter input file name:\n";

    string iname;
    cin >> iname;

    ifstream ifs{iname};

    if (!ifs) {
      error("can't open input file", iname);
    }

    // Throw exception only for really bad stream errors.
    // Normal fail() is still handled by our operator>> functions.
    ifs.exceptions(ifs.exceptions() | ios::badbit);

    // Open output file.
    cout << "Please enter output file name:\n";

    string oname;
    cin >> oname;

    ofstream ofs{oname};

    if (!ofs) {
      error("can't open output file", oname);
    }

    // Read an arbitrary number of years.
    vector<Year> ys;

    while (true) {
      Year y; // Important: get a fresh Year every time.

      if (!(ifs >> y)) {
        break;
      }

      ys.push_back(y);
    }

    cout << "read " << ys.size() << " years of readings\n";

    for (const Year &y : ys) {
      print_year(ofs, y);
    }

    return 0;
  } catch (exception &e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
  } catch (...) {
    cerr << "unknown error\n";
    return 2;
  }
}
