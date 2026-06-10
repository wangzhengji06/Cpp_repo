#include <iostream>
#include <vector>

std::vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(const std::vector<int> list) {
  std::vector<int> lv(10);
  for (int i = 0; i < 10; ++i)
    lv[i] = gv[i];
  for (int i : lv)
    std::cout << i << "\n";
  std::vector<int> lv2 = list;
  for (int i : lv2)
    std::cout << i << '\n';
}
