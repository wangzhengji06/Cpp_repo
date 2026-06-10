char *cat_dot(const char *s1, const char *s2) {
  // get s1 length, get s2 length, allocate space, give the assignment, return
  int length1 = 0;
  int length2 = 0;
  const char *p = s1;
  while (*p != 0) {
    ++p;
    ++length1;
  }
  p = s2;
  while (*p != 0) {
    ++p;
    ++length2;
  }
  char *result = new char[length1 + length2 + 2];
  for (int i = 0; i < length1 + length2 + 1; ++i) {
    if (i < length1)
      result[i] = s1[i];
    else if (i > length1)
      result[i] = s2[i - length1 - 1];
    else
      result[i] = '.';
  }
  result[length1 + length2 + 1] = 0;

  return result;
}
