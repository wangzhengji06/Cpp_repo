#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

struct Score {
  int bulls = 0;
  int cows = 0;
};

Score score(const std::vector<int> &secret, const std::vector<int> &guess) {
  if (secret.size() != guess.size()) {
    throw std::runtime_error("secret and guess have different sizes");
  }

  Score result;

  std::vector<bool> secret_used(secret.size(), false);
  std::vector<bool> guess_used(guess.size(), false);

  // First pass: bulls
  for (std::size_t i = 0; i < secret.size(); ++i) {
    if (secret.at(i) == guess.at(i)) {
      ++result.bulls;
      secret_used.at(i) = true;
      guess_used.at(i) = true;
    }
  }

  // Second pass: cows
  for (std::size_t i = 0; i < guess.size(); ++i) {
    if (guess_used.at(i)) {
      continue;
    }

    for (std::size_t j = 0; j < secret.size(); ++j) {
      if (secret_used.at(j)) {
        continue;
      }

      if (guess.at(i) == secret.at(j)) {
        ++result.cows;
        guess_used.at(i) = true;
        secret_used.at(j) = true;
        break;
      }
    }
  }

  return result;
}

std::vector<int> make_secret() {
  std::random_device rd;
  std::default_random_engine engine(rd());
  std::uniform_int_distribution<int> dist(0, 9);

  std::vector<int> secret;

  for (int i = 0; i < 4; ++i) {
    secret.push_back(dist(engine));
  }

  return secret;
}

int main() {
  try {
    std::vector<int> secret = make_secret();

    while (true) {
      int x1;
      int x2;
      int x3;
      int x4;

      std::cout << "Please enter your guess: ";

      if (!(std::cin >> x1 >> x2 >> x3 >> x4)) {
        throw std::runtime_error("bad input");
      }

      std::vector<int> guess = {x1, x2, x3, x4};

      Score result = score(secret, guess);

      std::cout << result.bulls << " bull(s) and " << result.cows
                << " cow(s)\n";

      if (result.bulls == 4) {
        std::cout << "You win!\n";
        break;
      }
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
}
