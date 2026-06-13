template <typename T> class unique_ptr {
  T *my_ptr;

public:
  explicit unique_ptr(T *val) : my_ptr{val} {};
  ~unique_ptr() { delete my_ptr; }
  unique_ptr(const unique_ptr &) = delete;
  unique_ptr &operator=(const unique_ptr &) = delete;
  T *operator->() { return my_ptr; }
  T &operator*() { return *my_ptr; }
  T *release() {
    T *raw = my_ptr;
    my_ptr = nullptr;
    return raw;
  };
};
