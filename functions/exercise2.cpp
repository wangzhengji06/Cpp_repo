#include <iostream>
#include <limits>
#include <string>
#include <vector>

void print(const std::string &label, const std::vector<int> &v) {
  std::cout << label << ": ";

  for (int i : v) {
    std::cout << i << ' ';
  }

  std::cout << '\n';
}

void fibonacci(int x, int y, std::vector<int> &v, int n) {
  if (n <= 0)
    return;

  v.push_back(x);

  if (n == 1)
    return;

  v.push_back(y);

  for (int i = 2; i < n; ++i) {
    int prev = v[v.size() - 2];
    int curr = v[v.size() - 1];

    if (curr > std::numeric_limits<int>::max() - prev) {
      std::cout << "Stopping: next Fibonacci number would overflow int.\n";
      return;
    }

    v.push_back(prev + curr);
  }
}

int main() {
  std::vector<int> v;

  fibonacci(1, 1, v, 50);

  print("Fibonacci", v);

  std::cout << "largest generated value: " << v.back() << '\n';
  std::cout << "int max: " << std::numeric_limits<int>::max() << '\n';
}
