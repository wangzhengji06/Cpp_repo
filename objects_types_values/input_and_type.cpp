#include <iostream>

int main() {
  std::cout << "Please enter your first name and ages\n";
  std::string first_name;
  int age;
  std::cin >> first_name >> age;
  std::cout << "Hello, " << first_name << "(age in months " << age * 12
            << ")\n";
  return 0;
}
