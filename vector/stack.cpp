#include <iostream>
int main() {
  int stack_var1;
  int stack_var2;

  int *heap_var1 = new int;
  int *heap_var2 = new int;

  std::cout << "Stack var1 address: " << &stack_var1 << "\n";
  std::cout << "Stack var2 address: " << &stack_var2 << "\n";
  std::cout << "Heap var1 address:  " << heap_var1 << "\n";
  std::cout << "Heap var2 address:  " << heap_var2 << "\n";

  delete heap_var1;
  delete heap_var2;
}

