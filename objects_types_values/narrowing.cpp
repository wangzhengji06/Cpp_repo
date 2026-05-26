#include <iostream>

int main() {
  int x = 1000;
  char a = x;
  std::cout << "The narrowing of x turns it into :" << a << "\n";
}
