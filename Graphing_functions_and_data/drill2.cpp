#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

const std::string forbidden = ";:\"’[]*&^%$#@!";

struct Person {
public:
  Person(std::string, std::string, int);
  std::string first_name() const;
  std::string last_name() const;
  int age() const;

private:
  std::string first_name_;
  std::string last_name_;
  int age_;
};

void error() { throw std::runtime_error("Cannot create such Person"); }

Person::Person(std::string first_name, std::string last_name, int new_age)
    : first_name_{first_name}, last_name_{last_name}, age_{new_age} {
  if (age_ < 0 || age_ >= 150)
    error();
  std::string full_name = first_name + last_name;
  for (char c : full_name) {
    if (forbidden.find(c) != std::string::npos)
      error();
  }
}

std::string Person::first_name() const { return first_name_; }

std::string Person::last_name() const { return last_name_; }

int Person::age() const { return age_; }

std::istream &operator>>(std::istream &is, Person &p) {
  char ch1 = 0;
  char ch2 = 0;
  char ch3 = 0;
  char ch4 = 0;
  std::string first_name;
  std::string last_name;
  int age = 0;

  if (is >> ch1 >> first_name >> ch2 >> last_name >> ch3 >> age >> ch4) {
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
      is.clear(std::ios_base::failbit);
    else
      p = Person{first_name, last_name, age};
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, const Person &p) {

  os << '(' << p.first_name() << ',' << p.last_name() << ',' << p.age() << ')';
  return os;
}

int main() {
  std::vector<Person> people;
  Person p{"Goofy", "Goo", 63};
  std::cout << p.first_name() << ", " << p.age() << "\n";

  Person pp{"Default", "Default", 0};
  std::cout << "Now it is your term: \n";
  while (std::cin >> pp) {
    people.push_back(pp);
  }
  for (const Person &temp : people) {
    std::cout << temp << "\n";
  }
}
