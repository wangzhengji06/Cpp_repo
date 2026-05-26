#include <iostream>

int main() {
  std::cout << "Enter the name of the person you want to write to as well as "
               "his friend and his age: ";
  std::string firstname;
  std::string friend_name;
  int age;
  std::cin >> firstname >> friend_name >> age;
  if (age <= 0 or age >= 110)
    std::cout << "You are kidding me right?";
  std::cout << "Dear " << firstname << "\n";
  std::cout << "  How are you? I am fine. I miss you.\n";
  std::cout << "  Have you seen " << friend_name << " lately?\n";
  std::cout << "  I hear you just had a birthday and you are " << age
            << "years old.\n";
  std::cout << "  Next year you will be " << age + 1 << ".\n";
}
