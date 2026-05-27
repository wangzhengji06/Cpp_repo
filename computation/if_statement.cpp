#include <iostream>

int main() {
  int a = 0;
  int b = 0;
  std::cout << "Please enter two integers: \n";
  std::cin >> a >> b;

  if (a < b)
    std::cout << a << " is smaller than " << b << "\n";
  else
    std::cout << a << " is larger than or equal to " << b << "\n";
}
