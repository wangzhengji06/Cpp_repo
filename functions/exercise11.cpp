#include <algorithm>
#include <stdexcept>
#include <vector>

struct Stats {
  double smallest;
  double largest;
  double mean;
  double median;
};

Stats compute_stats(const std::vector<double> &v) {
  if (v.empty()) {
    throw std::runtime_error("empty vector");
  }

  std::vector<double> sorted = v;
  std::sort(sorted.begin(), sorted.end());

  double sum = 0;
  for (double x : v) {
    sum += x;
  }

  double mean = sum / v.size();

  double median;
  int n = sorted.size();

  if (n % 2 == 1) {
    median = sorted[n / 2];
  } else {
    median = (sorted[n / 2 - 1] + sorted[n / 2]) / 2;
  }

  return Stats{sorted.front(), sorted.back(), mean, median};
}
