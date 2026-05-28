#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  try {
    std::vector<int> v;
    for (int x; std::cin >> x;)
      v.push_back(x);
    for (int i = 0; i <= v.size(); ++i)
      std::cout << "v[" << i << "] == " << v.at(i) << "\n";
  } catch (std::out_of_range) {
    std::cerr << "Oops! Range error\n";
    return 1;
  } catch (...) {
    std::cerr << "Exception: something went wrong\n";
    return 2;
  }
}
