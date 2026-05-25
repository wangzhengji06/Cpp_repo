#include <stdio.h>

#define PI 3.1415926

double add(int a, int b);

int main() {
  int num1, num2;
  double sum;

  printf("Enter two integers:");
  scanf("%d %d", &num1, &num2);

  sum = add(num1, num2);

  printf("Sum: %lf\n", sum);

  return 0;
}

double add(int a, int b) { return PI + a + b; }
