#include <iostream>
#include <random>

int main() {
  std::default_random_engine engine;
  std::uniform_int_distribution<int> dist(1, 6);

  for (int i = 0; i < 10; ++i)
    std::cout << dist(engine) << "";
}
