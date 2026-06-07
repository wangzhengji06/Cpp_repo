int fac(int n) { return n > 1 ? n * fac(n - 1) : 1; }

int fact(int n) {
  if (n <= 1)
    return 1;
  int ret = 1;
  for (int i = 2; i <= n; ++i) {
    ret *= i;
  }
  return ret;
}
