#include <iostream>

int main() {
  constexpr int max = 100;
  int n;
  std::cin >> n;

  constexpr int c1 = max + 7;
  const int c2 = n + 7;

  std::cout << c1 << " , " << c2 << "\n";
}
