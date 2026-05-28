#include <iostream>

int main() {
  double d = 0;
  std::cin >> d;
  if (!std::cin)
    std::cout << "An input mistake has been caugh!\n";
}
