#include <iostream>

int main() {
  int i = 0;
  while (i < 26) {
    std::cout << char('a' + i) << " " << 'a' + i << "\n";
    ++i;
  }
}
