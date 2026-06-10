
char *str_dup(const char *s) {
  int length = 0;
  while (s[length] != 0) {
    ++length;
  }
  length += 1;
  char *target = new char[length];
  for (int i = 0; i < length; ++i)
    target[i] = s[i];
  return target;
}
