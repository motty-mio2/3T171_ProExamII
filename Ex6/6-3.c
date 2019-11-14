#include <stdio.h>

unsigned long long factorial(unsigned int n) {  // 階乗計算 n!
  unsigned long long ans = 1;
  if (n > 0) {
    ans = n * factorial(n - 1);
  }
  return ans;
}

long double power(double x, unsigned int n) {  // x^n
  long double ans = 1;
  if (n == 0 || x == 0) {
    ans = 1;
  } else {
    for (int i = 0; i < n; i++) {
      ans *= x;
    }
  }
  return ans;
}

long double calcsin(double x, unsigned int n) {
  unsigned int nx = 2 * n + 1;
  long double flag = power(-1, n);
  long double ans;
  unsigned long long chi, mot;
  chi = power(x, nx);
  mot = factorial(nx);
  ans = flag * chi / mot;
  return ans;
}

long double calccos(double x, unsigned int n) {
  int nx = 2 * n;
  long double flag = power(-1, n);
  long double ans;
  unsigned long long chi, mot;
  chi = power(x, nx);
  mot = factorial(nx);
  ans = flag * chi / mot;
  return ans;
}

long double calcexp(double x, unsigned int n) {
  long double ans;
  unsigned long long chi, mot;
  chi = power(x, n);
  mot = factorial(n);
  ans = chi / mot;
  return ans;
}

int main() {
  double x;
  unsigned int n;
  printf("input numbers\n");
  printf("  x is --> ");
  scanf("%le", &x);
  printf("  n is --> ");
  scanf("%d", &n);
  long double csin, ccos, cexp;
  // double ans[9] = {0} * 9;
  /*
  long a = factorial(5);
  long b = power(5, 3);
  */

  csin = calcsin(x, n);
  ccos = calccos(x, n);
  cexp = calcexp(x, n);

  printf("-------------answer-----------\n");
  printf("  sin : %LF\n", csin);
  printf("  cos : %LF\n", ccos);
  printf("  exp : %LF\n", cexp);
  // printf("%ld\t%ld\n", a, b);

  return 0;
}