#include <cstdlib>
#include <numeric>
#include <ostream>
class Rational {
public:
  Rational(int n, int d);
  class Invalid {};
  int num() const;
  int den() const;
  double to_double() const;

private:
  int numerator;
  int denominator;
};

Rational::Rational(int n, int d) {
  if (d == 0)
    throw Invalid{};

  if (d < 0) {
    n = -n;
    d = -d;
  }

  int g = std::gcd(std::abs(n), d);

  numerator = n / g;
  denominator = d / g;
}

int Rational::num() const { return numerator; }

int Rational::den() const { return denominator; }

double Rational::to_double() const {
  return static_cast<double>(numerator) / denominator;
}

std::ostream &operator<<(std::ostream &os, const Rational &r) {
  return os << r.num() << "/" << r.den();
}

bool operator==(const Rational &r1, const Rational &r2) {
  return r1.num() == r2.num() && r1.den() == r2.den();
}

bool operator!=(const Rational &r1, const Rational &r2) { return !(r1 == r2); }

Rational operator+(const Rational &r1, const Rational &r2) {
  return Rational((r1.num() * r2.den() + r2.num() * r1.den()),
                  r1.den() * r2.den());
}

Rational operator-(const Rational &r1, const Rational &r2) {
  return Rational((r1.num() * r2.den() - r2.num() * r1.den()),
                  r1.den() * r2.den());
}

Rational operator*(const Rational &r1, const Rational &r2) {
  return Rational(r1.num() * r2.num(), r1.den() * r2.den());
}

Rational operator/(const Rational &r1, const Rational &r2) {
  return Rational((r1.num() * r2.den()), r1.den() * r2.num());
}
