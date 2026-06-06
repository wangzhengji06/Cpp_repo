#include <iostream>
#include <string>
class B1 {
public:
  virtual void vf() const { std::cout << "B1::vf()\n"; };
  void f() const { std::cout << "B1::f()\n"; };
  virtual void pvf() const = 0;
};

class B2 {
public:
  virtual void pvf() const = 0;
};

class D1 : public B1 {
public:
  void vf() const override { std::cout << "D1::vf()\n"; };
  void f() const { std::cout << "D1::f()\n"; };
};

class D2 : public D1 {
public:
  void pvf() const override { std::cout << "D2::pvf()\n"; };
};

class D21 : public B2 {
public:
  void pvf() const override { std::cout << var1 << "\n"; };

private:
  std::string var1 = "sometimes all you need is consistency";
};

class D22 : public B2 {
public:
  void pvf() const override { std::cout << var1 << "\n"; };

private:
  int var1 = 6;
};

void f(B2 &b2) { b2.pvf(); }

int main() {
  std::cout << "The program starts right now ----- \n";

  D2 object_d2;
  object_d2.f();
  object_d2.vf();
  object_d2.pvf();

  D21 d21;
  D22 d22;
  f(d21);
  f(d22);
}
