#include <iostream>
#include <ostream>
#include <vector>

void print_array(std::ostream &os, int *a, int n) {
  for (int i = 0; i < n; ++i)
    os << a[i] << "\n";
}

int main() {

  int *nice = new int[]{1, 2, 3, 4, 5, 6, 7, 9, 0, 10};
  print_array(std::cout, nice, 10);
  delete[] nice;
  std::vector<int> nice2;
  for (int i = 100; i < 10; ++i)
    nice2.push_back(i);
  for (int a : nice2)
    std::cout << a << "\n";
}
