#include <iostream>
#include <vector>

int main() {
  std::vector<int> v(6);

  for (int i : v) {
    std::cout << i << "\n";
  }

  std::cout << v.size() << "\n";
}
