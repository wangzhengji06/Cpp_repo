#include <iostream>

int main() {
  int number_of_words = 0;
  std::string previous;
  std::string current;
  while (std::cin >> current) {
    ++number_of_words;
    if (previous == current)
      std::cout << "repeated word:" << current << "\n";
    previous = current;
  }
}
