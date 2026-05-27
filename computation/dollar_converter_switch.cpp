#include <iostream>

int main() {
  constexpr double yen_to_dollar = 0.0063;
  constexpr double pound_to_dollar = 1.35;

  double amount;
  char currency;

  std::cout << "Please enter the amount followed by currency: \n";
  std::cin >> amount >> currency;

  switch (currency) {
  case ('y'):
    std::cout << "You have " << amount * yen_to_dollar << " dollars.\n";
    break;
  case ('p'):
    std::cout << "You have " << amount * pound_to_dollar << " dollars.\n";
    break;
  default:
    std::cout << "I have no idea what " << currency << " means.\n";
    break;
  }
}
