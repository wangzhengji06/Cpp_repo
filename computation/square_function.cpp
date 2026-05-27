#include <iostream>

int square(int v) {
  int sum = 0;
  for (int i = 1; i < v + 1; ++i) {
    sum += v;
  }
  return sum;
}

int main() {
  int selected_number;
  std::cout << "What is on your mind now?\n";
  std::cin >> selected_number;
  std::cout << "The final sum is " << square(selected_number) << "\n";
}
