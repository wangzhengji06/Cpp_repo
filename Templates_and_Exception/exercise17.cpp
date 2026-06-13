template <typename F> class Final_action {
  F f;

public:
  Final_action(F newf) { f = newf; };
  ~Final_action() { f(); }
};

template <typename F> Final_action<F> finally(F f) {
  return Final_action<F>{f};
}
