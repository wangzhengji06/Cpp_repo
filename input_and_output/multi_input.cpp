

// func() read(string)
// read string from cin
// Check the prefix
// Transform to integer
// Use Ostream to output the final result

#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

bool is_hex(const std::string &s) {
  return s.size() >= 3 && s[0] == '0' &&
         std::tolower(static_cast<unsigned char>(s[1])) == 'x';
}

bool is_oct(const std::string &s) {
  return s.size() >= 2 && s[0] == '0' && !is_hex(s);
}

int main() {
  std::cout << "Input the integer in whatever format you like: \n";
  std::string number;
  std::string kind;
  std::string digits;

  while (std::cin >> number) {
    int value = 0;

    if (is_hex(number)) {
      kind = "hexadecimal";
      digits = number.substr(2);
    } else if (is_oct(number)) {
      kind = "octal";
      digits = number.substr(1);
    } else {
      kind = "decimal";
      digits = number;
    }

    std::istringstream iss{digits};

    if (kind == "hexadecimal") {
      iss >> std::hex >> value;
    } else if (kind == "octal") {
      iss >> std::oct >> value;
    } else {
      iss >> std::dec >> value;
    }

    if (!iss) {
      std::cout << number << " is not a valid integer\n";
      continue;
    }

    std::cout << number << ' ' << kind << " converts to " << std::dec << value
              << " decimal\n";
  }
  if (std::cin.bad())
    throw std::runtime_error("input stream corrupted");
}
