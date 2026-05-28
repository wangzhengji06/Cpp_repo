#include <iostream>
#include <stdexcept>
#include <vector>

void score(std::vector<int> secret, std::vector<int> guess) {
  int bulls = 0;
  int cows = 0;

  std::vector<bool> secret_used(secret.size(), false);
  std::vector<bool> guess_used(guess.size(), false);
  std::vector<int> used;
  if (secret.size() != guess.size())
    throw std::runtime_error("there is something wrong with this game.");
  for (std::size_t i = 0; i < secret.size(); ++i) {
    if (secret.at(i) == guess.at(i)) {
      ++bulls;
      secret_used.at(i) = true;
      guess_used.at(i) = true;
    }
  }

  for (std::size_t i = 0; i < guess.size(); ++i) {
    if (guess_used.at(i))
      continue;

    for (std::size_t j = 0; j < secret.size(); ++j) {
      if (secret_used.at(j))
        continue;

      if (guess.at(i) == secret.at(j)) {
        ++cows;
        guess_used.at(i) = true;
        secret_used.at(j) = true;
        break;
      }
    }
  }

  std::cout << "bull is " << bulls << " and cow is " << cows << "\n";
}
