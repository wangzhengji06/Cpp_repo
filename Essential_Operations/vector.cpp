#include <initializer_list>
#include <iostream>

class Vector {
  int sz;
  double *elem;
  int space;

public:
  Vector();                                  // default constructor
  explicit Vector(int n);                    // consturctor
  Vector(std::initializer_list<double> lst); //{}
  Vector(const Vector &);                    // Copy constructor
  Vector &operator=(const Vector &);         // Copy assignment
  Vector(Vector &&arg);                      // Move constructor
  Vector &operator=(Vector &&arg);           // Move assignment
  ~Vector() { delete[] elem; }
  int size() const { return sz; };
  double &operator[](int n) { return elem[n]; }
  const double &operator[](int n) const { return elem[n]; }
  double *begin() const { return elem; }
  double *end() const { return elem + sz; }
  void reserve(int newalloc);
  int capacity() const { return space; }
  void resize(int newsize);
  void push_back(double d);
};

Vector::Vector() : sz{0}, elem{nullptr} {}

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

Vector &Vector::operator=(const Vector &a) {
  if (this == &a)
    return *this;

  if (a.sz <= space) {
    for (int i = 0; i < a.sz; ++i)
      elem[i] = a.elem[i];
    sz = a.sz;
    return *this;
  }

  double *p = new double[a.sz];
  for (int i = 0; i < a.sz; ++i)
    p[i] = a.elem[i];
  delete[] elem;

  space = sz = a.sz;
  elem = p;
  return *this;
}

Vector::Vector(Vector &&arg) : sz{arg.sz}, elem{arg.elem} {
  arg.sz = 0;
  arg.elem = nullptr;
}

Vector &Vector::operator=(Vector &&arg) {
  if (this != &arg) {
    delete[] elem;
    elem = arg.elem;
    sz = arg.sz;
    arg.elem = nullptr;
    arg.sz = 0;
  }
  return *this;
}

bool operator==(const Vector &v1, const Vector &v2) {
  if (v1.size() != v2.size())
    return false;
  for (int i = 0; i < v1.size(); ++i)
    if (v1[i] != v2[i])
      return false;
  return true;
}

bool operator!=(const Vector &v1, const Vector &v2) { return !(v1 == v2); }

void Vector::reserve(int newalloc) {
  if (newalloc <= space)
    return;
  double *p = new double[newalloc];
  for (int i = 0; i < sz; ++i) {
    p[i] = elem[i];
  }
  delete[] elem;
  elem = p;
  space = newalloc;
}

void Vector::resize(int newsize) {
  reserve(newsize);
  for (int i = sz; i < newsize; ++i)
    elem[i] = 0;
  sz = newsize;
}

void Vector::push_back(double d) {
  if (space == 0)
    reserve(8);
  else if (sz == space)
    reserve(2 * space);
  elem[sz] = d;
  ++sz;
}

int main() {}
