#include <iostream>

int area(int length, int width)
// calculate area of a rectangle
{
  return length * width;
}

int framed_area(int x, int y)
// calculate area within frame
{
  return area(x - 2, y - 2);
}

void test(int x, int y, int z) {
  int area1 = area(x, y);
  int area3 = framed_area(y, z);
  double ratio = double(area1) / area3;
  std::cout << ratio << "\n";
}

int main() {
  int x;
  int y;
  int z;
  std::cout << "Please input x, y, z: \n";
  std::cin >> x >> y >> z;
  test(x, y, z);
}
