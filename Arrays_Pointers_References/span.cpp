#include <exception>
#include <iostream>
#include <span>

void test(std::span<int> s) {
  std::cout << "size: " << s.size() << '\n';
  for (int x : s)
    std::cout << x << '\n';
  try {
    int y = s[s.size()];
  } catch (...) {
    std::cout << "we have range checking\n";
    return;
  }
  std::cout << "no range checking! Boo Hoo!\n";
  std::terminate();
}

int main() {
  const int max = 1024;
  int buf[max];
  std::span<int> sp{buf, max / 2};
  test(sp);
}
