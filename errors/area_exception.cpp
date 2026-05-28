#include <iostream>
class Bad_area {};

int area(int length, int width) {
  if (length <= 0 || width <= 0)
    throw Bad_area{};
  return length * width;
}

int framed_area(int length, int width) { return (length - 2) * (width - 2); }

void test(int x, int y, int z) {
  int area1 = area(x, y);
  int area2 = framed_area(1, z);
  int area3 = framed_area(y, z);
  double ratio = area1 / area3;
}

int main() try { test(-1, 2, 4); } catch (Bad_area) {
  std::cout << "Oops! bad arguments to area()\n";
}
