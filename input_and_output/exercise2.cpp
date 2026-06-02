#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>

void grep_toy(std::string word, std::string filename) {
  int line_num = 0;
  std::ifstream ist{filename};
  if (!ist)
    throw std::runtime_error("Cannot open such file!");

  ist.exceptions(ist.exceptions() | std::ios::badbit);
  std::string line;

  while (std::getline(ist, line)) {
    if (line.find(word) != std::string::npos) {
      std::cout << line_num << ": " << line << "\n";
    }
    ++line_num;
  }
}
