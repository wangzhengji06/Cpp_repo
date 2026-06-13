#include <vector>

template <typename T, typename U>
auto dot_product(const std::vector<T> &vt, const std::vector<U> &vu) {
  auto sum = vt[0] * vu[0];

  for (int i = 1; i < vt.size(); ++i)
    sum += vt[i] * vu[i];

  return sum;
}
