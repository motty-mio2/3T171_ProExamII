#include <stdio.h>

long factorial(int n) {  // 階乗計算 n!
  int ans = 1;
  if (n > 0) {
    ans = n * factorial(n - 1);
  }
  return ans;
}

long power(int x, int n) {  // x^n
  long ans = 1;
  if (n == 0 || x == 0) {
    ans = 1;
  } else {
    for (int i = 0; i < n; i++) {
      ans *= x;
    }
  }
  return ans;
}

int main() {
  // double ans[9] = {0} * 9;
  long a = factorial(5);
  long b = power(5, 3);
  printf("%ld\t%ld\n", a, b);

  return 0;
}