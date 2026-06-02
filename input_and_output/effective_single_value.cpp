#include <iostream>
#include <stdexcept>
#include <string>
void skip_to_int() {
  if (std::cin.fail()) { // we found something that wasn’t an integer
    std::cin.clear();    // we’d like to look at the characters
    for (char ch; std::cin >> ch;) { // throw away non-digits
      if (isdigit(ch) || ch == '-') {
        std::cin.unget(); // put the digit back, so that we can read the number
        return;
      }
    }
  }
  throw std::runtime_error("no input");
}

int get_int() {
  int n = 0;
  while (true) {
    if (std::cin >> n)
      return n;
    std::cout << "Sorry, that was not a number; please try again\n";
    skip_to_int();
  }
}

int get_int(int low, int high, const std::string &greeting,
            const std::string &sorry) {
  std::cout << greeting << ": [" << low << ':' << high << "]\n";
  while (true) {
    int n = get_int();
    if (low <= n && n <= high)
      return n;
    std::cout << sorry << ": [" << low << ':' << high << "]\n";
  }
}
