#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << "Please enter name-and-value pairs: \n";
  std::vector<std::string> names;
  std::vector<int> scores;

  std::string name;
  int score;

  while (std::cin >> name >> score && (name != "NoName" || score != 0)) {
    bool flag = false;
    for (std::string s : names) {
      if (s == name)
        flag = true;
    }
    if (flag) {
      std::cout << "Mistakes has been met and there is no going back \n";
      return 1;
    }
    names.push_back(name);
    scores.push_back(score);
  }

  for (int i = 0; i < names.size(); ++i) {
    std::cout << names[i] << "  " << scores[i] << "\n";
  }
}
