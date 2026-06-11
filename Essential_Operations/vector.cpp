#include <initializer_list>
#include <iostream>
class Vector {
  int sz;
  double *elem;

public:
  Vector(int n);
  Vector(std::initializer_list<double> lst);
  Vector(const Vector &);
  ~Vector() { delete[] elem; }
  int size() const { return sz; };
  double &operator[](int n) { return elem[n]; }
  const double &operator[](int n) const { return elem[n]; }
};

Vector::Vector(int n) : sz{n}, elem{new double[n]} {
  for (int i = 0; i < sz; ++i)
    elem[i] = 0.0;
}

Vector::Vector(std::initializer_list<double> lst)
    : sz{static_cast<int>(lst.size())}, elem{new double[sz]} {
  std::copy(lst.begin(), lst.end(), elem);
}

Vector::Vector(const Vector &arg) : sz{arg.sz}, elem{new double[arg.sz]} {
  std::copy(arg.elem, arg.elem + sz,
            elem); // copy elements [0:sz) from elem.arg into newelem;
}

int main() {
  Vector v1 = {1, 2, 3};
  Vector v2(3);
  Vector v3 = v2;
}
