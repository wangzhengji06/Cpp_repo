#include <iostream>
#include <limits>

int main() {
  int max_int = std::numeric_limits<int>::max();
  int prev = 1;
  int curr = 1;
  int n = 2;
  while (prev < max_int - curr) {
    int next = prev + curr;
    prev = curr;
    curr = next;
    ++n;
  }
  std::cout << n << " and " << curr << "\n";
}
