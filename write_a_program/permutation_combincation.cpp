#include <iostream>
#include <stdexcept>

int calculate_factorial(int x) {
  int res = 1;
  for (int i = 1; i <= x; ++i)
    res *= i;
  return res;
}

int main() {
  try {
    int a = 0;
    int b = 0;

    std::cout << "Please enter a and b:\n";
    std::cin >> a >> b;

    if (!std::cin)
      throw std::runtime_error("The input is not correct");

    if (a < 0 || b < 0 || a < b)
      throw std::runtime_error("Not valid numbers");

    std::cout << "Permutation or Combination? Use p or c:\n";

    char choice = 0;
    std::cin >> choice;

    if (!std::cin)
      throw std::runtime_error("Could not read choice");

    int result = 0;

    switch (choice) {
    case 'p':
      result = calculate_factorial(a) / calculate_factorial(a - b);
      break;

    case 'c':
      result = calculate_factorial(a) / calculate_factorial(a - b) /
               calculate_factorial(b);
      break;

    default:
      throw std::runtime_error("Computation cannot be executed");
    }

    std::cout << result << "\n";
    return 0;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception\n";
    return 2;
  }
}
