#include <iostream>
int ga[]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int *list) {
  int la[10]{};
  for (int i = 0; i < 10; ++i) {
    la[i] = *list;
    ++list;
  }
  list -= 10;
  for (int i : la) {
    std::cout << i << "\n";
  }
  int *p = new int[10];
  for (int i = 0; i < 10; ++i) {
    *p = *list;
    ++list;
    ++p;
  }
  p -= 10;
  for (int i = 0; i < 10; i++) {
    std::cout << *p << "\n";
    ++p;
  }
  p -= 10;
  delete[] p;
}
