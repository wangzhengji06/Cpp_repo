#include <iostream>
#include <pthread.h>

int main() {
  for (int i = 0; i < 26; ++i) {
    std::cout << char('a' + i) << " " << 'a' + i << "\n";
  }
}
