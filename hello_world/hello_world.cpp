#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::cout << "Hello, world!\n";

  std::vector<int> numbers{1, 2, 3};

  try {
    std::cout << "numbers.at(1) = " << numbers.at(1) << '\n';
    std::cout << "numbers.at(10) = " << numbers.at(10) << '\n';
  } catch (const std::out_of_range &e) {
    std::cerr << "Range error: " << e.what() << '\n';
  }

  return 0;
}
