#include "foo.h"

int main() {
  extern int foo;

  print_foo();

  print(foo);
}
