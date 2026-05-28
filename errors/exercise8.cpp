#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void error(std::string s1) { throw std::runtime_error{s1}; }

int main() {
  try {
    int N;

    std::cout << "Please enter the number of values you want to sum:\n";
    std::cin >> N;

    if (!std::cin)
      error("The number of values is not an integer");

    if (N <= 0)
      error("The number of values must be positive");

    std::cout << "Please enter some integers (press '|' to stop):\n";

    std::vector<int> numbers;

    for (int s; std::cin >> s;) {
      numbers.push_back(s);
    }

    if (static_cast<std::size_t>(N) > numbers.size())
      error("Not enough values");

    int sum = 0;

    std::cout << "The sum of the first " << N << " numbers ( ";

    for (int i = 0; i < N; ++i) {
      sum += numbers.at(i);
      std::cout << numbers.at(i) << ' ';
    }

    std::cout << ") is " << sum << '\n';

    return 0;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
}
