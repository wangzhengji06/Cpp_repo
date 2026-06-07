#include <PPP/Graph.h>
#include <PPP/Simple_window.h>

struct Distribution {
  int year;
  double young, middle, old;
};

istream &operator>>(istream &is, Distribution &d) {
  char ch1 = 0;
  char ch2 = 0;
  char ch3 = 0;
  Distribution dd;

  if (is >> ch1 >> dd.year >> ch2 >> dd.young >> dd.middle >> dd.old >> ch3) {
    if (ch1 != '{' || ch2 != ':' || ch3 != '}')
      is.clear(ios_base::failbit);
    else
      d = dd;
  }
  return is;
}

int main() {
};
