#include <iostream>

int main() {
  int i2[]{1, 2, 3, 4, 5, 6};
  std::cout << sizeof(i2) << "\n";
  std::cout << sizeof(*i2) << "\n";
  int *i = i2;
}
