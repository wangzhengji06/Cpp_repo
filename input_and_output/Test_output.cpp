#include <format>
#include <iostream>
int birth_year = 1997;
int age = 28;

int main() {
  std::cout << std::format("{:d} \t {:x} \t {:o} \n", birth_year, birth_year,
                           birth_year); // decimal hexadecimal octal
  std::cout << age;
}
