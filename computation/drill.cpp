#include <iostream>
#include <sys/types.h>

int main() {
  double a;
  double b;
  double small;
  double large;

  while (std::cin >> a >> b) {
    if (a < b) {
      small = a;
      large = b;
    } else {
      small = b;
      large = a;
    }

    if (small == large) {
      std::cout << "the numbers are equal.\n";
    } else {
      std::cout << "the smaller value is " << small << "\n";
      std::cout << "the larger value is " << large << "\n";
    }
  }
}
