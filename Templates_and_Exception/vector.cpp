#include <algorithm>
#include <initializer_list>
#include <limits>
#include <memory>
#include <stdexcept>

int reasonable_size = std::numeric_limits<int>::max();

struct out_of_range {};

template <typename T, typename A = std::allocator<T>> class Vector {
  A alloc;
  int sz;
  T *elem;
  int space;

public:
  Vector();
  explicit Vector(int n);
  Vector(std::initializer_list<T> lst);
  Vector(const Vector &arg);
  Vector &operator=(const Vector &a);
  Vector(Vector &&arg);
  Vector &operator=(Vector &&arg);
  ~Vector() { delete[] elem; }

  int size() const { return sz; }
  int capacity() const { return space; }

  T &at(int n);
  const T &at(int n) const;

  T &operator[](int n) { return elem[n]; }
  const T &operator[](int n) const { return elem[n]; }

  T *begin() { return elem; }
  T *end() { return elem + sz; }
  const T *begin() const { return elem; }
  const T *end() const { return elem + sz; }

  void reserve(int newalloc);
  void resize(int newsize, T def = T{});
  void push_back(T d);
};

template <typename T, typename A>
Vector<T, A>::Vector() : sz{0}, elem{nullptr}, space{0} {}

template <typename T, typename A>
Vector<T, A>::Vector(int n) : sz{n}, elem{new T[n]}, space{n} {
  if (!(0 < n && n < reasonable_size))
    throw std::length_error{"size too large for vector"};
  for (int i = 0; i < sz; ++i)
    elem[i] = T{};
}

template <typename T, typename A>
Vector<T, A>::Vector(std::initializer_list<T> lst)
    : sz{static_cast<int>(lst.size())}, elem{new T[sz]}, space{sz} {
  std::copy(lst.begin(), lst.end(), elem);
}

template <typename T, typename A>
Vector<T, A>::Vector(const Vector<T, A> &arg)
    : sz{arg.sz}, elem{new T[arg.sz]}, space{arg.sz} {
  std::copy(arg.elem, arg.elem + sz, elem);
}

template <typename T, typename A>
Vector<T, A> &Vector<T, A>::operator=(const Vector<T, A> &a) {
  if (this == &a)
    return *this;

  if (a.sz <= space) {
    for (int i = 0; i < a.sz; ++i)
      elem[i] = a.elem[i];
    sz = a.sz;
    return *this;
  }

  T *p = new T[a.sz];
  for (int i = 0; i < a.sz; ++i)
    p[i] = a.elem[i];

  delete[] elem;
  elem = p;
  sz = a.sz;
  space = a.sz;

  return *this;
}

template <typename T, typename A>
Vector<T, A>::Vector(Vector<T, A> &&arg)
    : sz{arg.sz}, elem{arg.elem}, space{arg.space} {
  arg.sz = 0;
  arg.elem = nullptr;
  arg.space = 0;
}

template <typename T, typename A>
Vector<T, A> &Vector<T, A>::operator=(Vector<T, A> &&arg) {
  if (this != &arg) {
    delete[] elem;

    elem = arg.elem;
    sz = arg.sz;
    space = arg.space;

    arg.elem = nullptr;
    arg.sz = 0;
    arg.space = 0;
  }

  return *this;
}

template <typename T, typename A>
bool operator==(const Vector<T, A> &v1, const Vector<T, A> &v2) {
  if (v1.size() != v2.size())
    return false;

  for (int i = 0; i < v1.size(); ++i)
    if (v1[i] != v2[i])
      return false;

  return true;
}

template <typename T, typename A>
bool operator!=(const Vector<T, A> &v1, const Vector<T, A> &v2) {
  return !(v1 == v2);
}

template <typename T, typename A> void Vector<T, A>::reserve(int newalloc) {
  if (newalloc <= space)
    return;

  T *p = alloc.allocate(newalloc);

  std::uninitialized_move(elem, &elem[sz], p);

  std::destroy(elem, elem + sz);
  alloc.deallocate(elem, capacity());
  elem = p;
  space = newalloc;
}

template <typename T, typename A>
void Vector<T, A>::resize(int newsize, T val) {
  reserve(newsize);
  if (sz < newsize)
    std::uninitialized_fill(&elem[sz], &elem[newsize], val);
  if (newsize < sz)
    std::destroy(&elem[newsize], &elem[sz]);
  sz = newsize;
}

template <typename T, typename A> void Vector<T, A>::push_back(T val) {
  reserve((space == 0) ? 8 : 2 * space);
  std::construct_at(&elem[sz], val);
  ++sz;
}

template <typename T, typename A> T &Vector<T, A>::at(int n) {
  if (n < 0 || sz <= n)
    throw out_of_range();
  return elem[n];
}

template <typename T, typename A> const T &Vector<T, A>::at(int n) const {
  if (n < 0 || sz <= n)
    throw out_of_range();
  return elem[n];
}

int main() {
  Vector<int> vi{1, 2, 3};
  vi.push_back(4);

  Vector<double> vd(5);
  vd.resize(10);

  Vector<int> v2 = vi;
  Vector<int> v3 = std::move(v2);
}
