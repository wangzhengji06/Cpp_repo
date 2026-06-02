#include <algorithm>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main() {

  // 1. Read the file name
  std::string filename;
  std::cout << "Please tell me the file name: \n";
  std::cin >> filename;

  // 2. Open the file
  std::ifstream ifs{filename};

  if (!ifs)
    throw std::runtime_error("Such file cannot be read.\n");

  // 3. Use the ifs to read all numbers(int)
  int number;
  std::vector<int> numbers;
  while (true) {
    if (ifs >> number)
      numbers.push_back(number);
    // Cannot normally read file
    else if (ifs.bad())
      throw std::runtime_error("Broken file? \n");
    else if (ifs.eof())
      break;
    // If failed, see if it is terminator
    else if (ifs.fail()) {
      ifs.clear();
      char c = 0;
      if (ifs >> c && c == '*') {
        break;
      } else {
        ifs.unget();
        ifs.clear(std::ios::failbit);
      }
    }
  }

  // 4. Sort the number vectors
  std::sort(numbers.begin(), numbers.end());
  if (numbers.empty())
    return 0;
  else {
    int prev = numbers[0];
    int count = 1;
    for (int i = 1; i < numbers.size(); ++i) {
      if (numbers[i] == prev)
        ++count;
      else {
        std::cout << prev << '\t' << count << '\n';
        prev = numbers[i];
        count = 1;
      }
    }
    std::cout << prev << '\t' << count << '\n';
  }
}
