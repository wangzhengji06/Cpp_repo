#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {5, 7, 9, 4, 6, 8};
  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << '\n';
}
