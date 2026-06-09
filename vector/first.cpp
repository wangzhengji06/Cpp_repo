#include <iostream>
#include <vector>

class Vector {
  int sz;
  double *elem;

public:
  Vector(int s);
  int size() const { return sz; }
};

void sizes(char ch, int i, int *p) {
  std::cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch)
            << '\n';
  std::cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
  std::cout << "the size of int* is" << sizeof(int *) << ' ' << sizeof(p)
            << '\n';
}

int main() {
  char ch1 = '0';
  int i = 1;
  int *p = &i;

  sizes(ch1, i, p);

  std::vector<int> v(1000);
  std::cout << "The size of vector <int>(1000) is " << sizeof(v) << '\n';
}
