#include <iostream>
#include <ostream>
#include <string>
#include <vector>
enum class Month { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

std::vector<std::string> month_tbl = {
    "January", "February", "March",     "April",    "May",      "June",
    "July",    "Augusdt",  "September", "Octorber", "November", "December"};

int to_int(Month m) { return static_cast<int>(m); }

Month operator++(Month &m) {
  m = (m == Month::dec) ? Month::jan : Month{to_int(m) + 1};
  return m;
}

std::ostream &operator<<(std::ostream &os, Month m) {
  return os << month_tbl[to_int(m)];
}

int main() {
  Month m{1};
  std::cout << m;
  ++m;
  std::cout << m;
}
