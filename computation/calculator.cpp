#include <iostream>
#include <string>

int main() {
  std::cout
      << "Please give me three arguments: number, number, and operator:\n";

  double num_1;
  double num_2;
  char operator_selected;

  while (std::cin >> num_1 >> num_2 >> operator_selected) {
    double result = 0.0;
    std::string result_name;

    switch (operator_selected) {
    case '+': {
      result = num_1 + num_2;
      result_name = "sum";
      break;
    }

    case '-': {
      result = num_1 - num_2;
      result_name = "difference";
      break;
    }

    case '*': {
      result = num_1 * num_2;
      result_name = "product";
      break;
    }

    case '/': {
      if (num_2 == 0) {
        std::cout << "Cannot divide by zero.\n";
        continue;
      }

      result = num_1 / num_2;
      result_name = "quotient";
      break;
    }

    default: {
      std::cout << "Unknown operator: " << operator_selected << "\n";
      continue;
    }
    }

    std::cout << "The " << result_name << " of " << num_1 << " and " << num_2
              << " is " << result << "\n";
  }
}
