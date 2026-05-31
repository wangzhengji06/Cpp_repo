#include <iostream>

int f(int);

int f(int num) { return num + 1; }

int main() {
  int i = 7;
  std::cout << f(i) << "\n";
}
