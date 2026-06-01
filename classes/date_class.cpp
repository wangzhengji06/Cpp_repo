#include <ostream>
class Date {
public:
  Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {}
  void add_day(int n);
  int day() { return d; }
  int month() { return m; }
  int year() { return y; }
  // ...
private:
  int y, m, d; // year, month, day
};

std::ostream &operator<<(std::ostream &os, Date d) {
  return os << d.year() << '/' << d.month() << ' /' << d.day();
}
