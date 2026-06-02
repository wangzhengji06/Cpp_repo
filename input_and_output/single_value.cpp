#include <cctype>
#include <iostream>
#include <stdexcept>
int get10() {
  std::cout << "Please enter an ingeteger in the range 1 to 10 (inclusive):\n";
  int n = 0;
  while (true) {
    std::cin >> n;
    if (std::cin) {
      if (1 <= n && n <= 10)
        return n;
      std::cout << "Sorry" << n << " is not in the range, please try again\n";
    } else if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Sorry, that was not a number, please try again\n";
      for (char ch; std::cin >> ch && !isdigit(ch);)
        ;
      if (!std::cin)
        throw std::runtime_error("no input");
      std::cin.unget();
    } else
      throw std::runtime_error("no input");
  }
}

int main() { std::cout << get10(); }
