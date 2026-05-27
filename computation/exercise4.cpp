#include <iostream>
#include <vector>

int main() {
  std::vector<double> distances;

  for (double distance; std::cin >> distance;) {
    distances.push_back(distance);
  }

  double sum = 0.0;
  double smallest = distances[0];
  double greatest = distances[0];

  for (double distance : distances) {
    sum += distance;

    if (distance < smallest) {
      smallest = distance;
    }

    if (distance > greatest) {
      greatest = distance;
    }
  }

  double mean = sum / distances.size();

  std::cout << "The sum is " << sum << "\n";
  std::cout << "The smallest is " << smallest << "\n";
  std::cout << "The greatest is " << greatest << "\n";
  std::cout << "The mean is " << mean << "\n";
}
