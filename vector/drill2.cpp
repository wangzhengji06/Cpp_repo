#include <iostream>
#include <vector>

int main() {
  int nice = 7;
  int *p1 = &nice;

  std::cout << p1 << ' ' << *p1 << "\n";

  int *nice_array = new int[]{1, 2, 4, 8, 16, 32, 64, 128};
  int *p2 = nice_array;
  std::cout << p2 << ' ' << *p2 << "\n";

  int *p3 = p2;

  p1 = p2;

  p3 = p2;

  std::cout << p1 << ' ' << *p1 << ' ' << p2 << ' ' << *p2 << '\n';

  delete[] nice_array;

  p1 = new int[10];
  for (int i = 0; i < 10; ++i) {
    p1[i] = 2 * i;
  }


  p2 = new int[10];

  for (int i = 0; i < 10; ++i) {
    p2[i] = p1[i];
  }
  std::vector<int> v1(10);

  std::vector<int> v2 = v1; 
}
