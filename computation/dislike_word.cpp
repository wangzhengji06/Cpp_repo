#include <iostream>
#include <string>
#include <vector>

int main() {

  std::vector<std::string> disliked = {"Brocolli", "yes", "no"};
  for (std::string input; std::cin >> input;) {
    bool flag = false;
    for (std::string forbidden_word : disliked) {
      if (forbidden_word == input) {
        flag = true;
      }
    }
    if (flag == true) {
      std::cout << "beep\n";
    } else {
      std::cout << input << "\n";
    }
  }
}
