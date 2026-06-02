#include <format>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

void read_and_write_numbers(const std::string &input_file_name,
                            const std::string &output_file_name) {
  std::ifstream ist{input_file_name};

  if (!ist)
    throw std::runtime_error("Cannot open input file...");

  std::vector<double> temps;
  double number = 0;
  int count = 0;

  while (ist >> number) {
    temps.push_back(number);
  }

  if (ist.bad())
    throw std::runtime_error("Cannot read this file...");

  std::ofstream ost{output_file_name};

  if (!ost)
    throw std::runtime_error("Cannot open output file...");

  for (double x : temps) {
    ost << std::format("{:20.8e}", x);
    ++count;

    if (count % 4 == 0)
      ost << '\n';
  }
}
