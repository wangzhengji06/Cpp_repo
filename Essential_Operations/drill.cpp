class Ptr {
  double *p;

public:
  Ptr() : p(new double{}) {}

  explicit Ptr(double x) : p(new double(x)) {}

  Ptr(const Ptr &other) : p(new double(*other.p)) {}

  Ptr &operator=(const Ptr &other) {
    if (this != &other)
      *p = *other.p;

    return *this;
  }

  Ptr(Ptr &&other) noexcept : p(other.p) { other.p = nullptr; }

  Ptr &operator=(Ptr &&other) noexcept {
    if (this != &other) {
      delete p;

      p = other.p;
      other.p = nullptr;
    }

    return *this;
  }

  ~Ptr() { delete p; }

  double &operator*() { return *p; }

  const double &operator*() const { return *p; }
};
