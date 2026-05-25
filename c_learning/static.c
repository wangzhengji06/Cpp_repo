#include <stdio.h>

void StaticExample() {
  static int count = 0;
  count++;
  printf("Count = %d\n", count);
}

int main() {
  StaticExample();
  StaticExample();
  StaticExample();
  return 0;
}
