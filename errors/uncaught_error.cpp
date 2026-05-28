#include <stdexcept>
#include <string>

void error(std::string s1) { throw std::runtime_error{s1}; }

void test() { error("it just happens"); }

int main() { test(); }
