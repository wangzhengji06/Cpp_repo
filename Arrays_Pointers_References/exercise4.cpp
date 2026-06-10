int str_cmp(const char *s1, const char *s2) {
  while (*s1 != 0 && *s2 != 0) {
    if (*s1 < *s2)
      return -1;
    else if (*s1 > *s2)
      return 1;
    else {
      ++s1;
      ++s2;
    }
  }
  if (*s1 == 0 && *s2 != 0)
    return -1;
  else if (*s1 != 0 && *s2 == 0)
    return 1;
  return 0;
}

int str_cmp(const char *s1, const char *s2, int max_length) {
  int i = 0;
  while (*s1 != 0 && *s2 != 0 && i < max_length - 1) {
    if (*s1 < *s2)
      return -1;
    else if (*s1 > *s2)
      return 1;
    else {
      ++i;
      ++s1;
      ++s2;
    }
  }
  if (*s1 == 0 && *s2 != 0)
    return -1;
  else if (*s1 != 0 && *s2 == 0)
    return 1;
  return 0;
}

int main() {}
