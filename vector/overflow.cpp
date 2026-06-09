#include <iostream>

int main() {
  char *char_array = new char[10];
  int check_val = 123456;
  int i = 0;
  while (std::cin) {
    char c;
    std::cin >> c;
    if (c == '!')
      break;
    else
      char_array[i] = c;
    ++i;
  }
  std::cout << "check is now" << check_val << "\n";
}
