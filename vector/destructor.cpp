
#include <iostream>
struct Animal {
  Animal(int age);
  virtual ~Animal() { std::cout << "This Animal has been deleted"; }
  virtual void bark() const;
  int return_age() const { return a; }

private:
  int a;
};

Animal::Animal(int age) : a{age} {
  std::cout << "An animcal with " << age << " has been created!";
}

void Animal::bark() const { std::cout << "Animal noise\n"; }

struct Dog : Animal {
  Dog(int age, char type) : Animal(age), t(type) {};
  ~Dog() override { std::cout << "This is deleted for sure"; }
  void bark() const override { std::cout << "Woof woof"; }
  int return_type() const { return t; }

private:
  char t;
};

int main() {
  Animal *p = new Dog(5, 'A');

  p->bark();

  delete p;
}
