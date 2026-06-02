#include <fstream>
#include <stdexcept>
#include <vector>
struct Reading {
  int hour;
  double temperature;
};

int main() {
  std::ifstream ist{"temperature.txt"};
  std::vector<Reading> temps;
  int hour;
  double temperature;

  while (ist >> hour >> temperature) {
    if (hour < 0 || 23 < hour)
      throw std::runtime_error("hour out of range");
    temps.push_back(Reading{hour, temperature});
  }

  std::ofstream ost{"temperature2.txt"};
  for (Reading x : temps)
    ost << '(' << x.hour << ',' << x.temperature << ")\n";
}
