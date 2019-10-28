#include <math.h>
#include <stdio.h>

double pythagoras(double a, double b) {
  double c = sqrt(pow(a, 2) + pow(b, 2));
  return c;
}

int main() {
  double a, b;
  printf("input 2 numbers\n 1st:");
  scanf("%lf", &a);
  printf(" 2nd:");
  scanf("%lf", &b);

  double ans = pythagoras(a, b);

  printf("%f\n", ans);
}