#include <cmath>
#include <iostream>

int main() {
  std::cout << "Please enter a floating-point value: ";
  int n;
  std::cin >> n;
  std::cout << "n== " << n << "\nn+1== " << n + 1
            << "\nthree times n== " << 3 * n << "\ntwice n== " << n + n << "\n"
            << "\nsuqare root of n== " << std::sqrt(n)
            << "\nThe % of 3 of n == " << n % 3 << "\n";
}
