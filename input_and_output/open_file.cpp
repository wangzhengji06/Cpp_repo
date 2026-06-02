#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
  std::cout << "Please enter input file name: ";
  std::string iname;
  std::cin >> iname;
  std::ifstream ist{iname};
  if (!ist)
    throw std::runtime_error("Cannot open input file" + iname);

  std::cout << "Please enter name of output file: ";
  std::string oname;
  std::cin >> oname;
  std::ofstream ost{oname};
  if (!ost)
    throw std::runtime_error("Cannot open output file" + oname);
}
