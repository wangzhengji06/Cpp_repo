#include <iostream>

#include <istream>
#include <string>
#include <vector>
template <typename T> struct S {
  S(T x);
  T &access();
  const T &access() const;
  S &operator=(const T &);

private:
  T val;
};

template <typename T> S<T>::S(T x) : val{x} {}

template <typename T> T &S<T>::access() { return val; }

template <typename T> const T &S<T>::access() const { return val; }

template <typename T> S<T> &S<T>::operator=(const T &other) {
  val = other;
  return *this;
}

template <typename T> void read_val(T &v) {
  std::cout << "Give me some valid input\n";
  std::cin >> v;
}

template <typename T>
std::istream &operator>>(std::istream &is, const std::vector<T> &v) {
  char ch;
  is >> ch;
  if (ch != '{') {
    is.unget();
    is.clear(std::ios_base::failbit);
    return is;
  }

  v.clear();

  T val;
  while (is >> val) {
    v.push_back(val);

    is >> ch;
    if (ch == '}')
      return is;
    if (ch != ',') {
      is.clear(std::ios_base::failbit);
      return is;
    }
  }

  return is;
}

template <typename T>
std::ostream &operator<<(std::ostream &oss, std::vector<T> &target) {
  oss << "{ ";
  for (T x : target)
    oss << x << ", ";
  oss << " }";
  return oss;
}

int main() {
  S<int> a{3};
  S<char> b{'0'};
  S<double> c{3.0};
  S<std::string> d{"Life is short isn't it"};
  S<std::vector<int>> e{std::vector<int>{1, 2, 3}};

  read_val(a.access());
  read_val(b.access());
  read_val(c.access());
  read_val(d.access());

  std::cout << a.access() << "\n";
  std::cout << b.access() << "\n";
  std::cout << c.access() << "\n";
  std::cout << d.access() << "\n";
  for (int x : e.access())
    std::cout << x << "\n";
}
