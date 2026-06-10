#include <iostream>
#include <string>

bool is_palindrome_string(const std::string &s) {
  int first = 0;
  int last = s.length() - 1;
  while (first < last) {
    if (s[first] != s[last])
      return false;
    ++first;
    --last;
  }
  return true;
}

bool is_palindrome(const char *first, const char *last) {
  {
    while (first < last) {
      if (*first != *last)
        return false;
      ++first;
      --last;
    }
    return true;
  }
}

int main() {}
