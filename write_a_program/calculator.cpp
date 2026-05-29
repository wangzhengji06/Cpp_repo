#include <iostream>

int main() {
  std::cout << "Please enter expression (we can handle + or -): ";
  int lval = 0;
  int rval = 0;
  char op = 0;
  int res = 0;
  std::cin >> lval >> op >> rval;

  if (op == '+')
    res = lval + rval;
  else if (op == '-')
    res = lval - rval;
  std::cout << "Result: " << res << "\n";
}
