#include <stdio.h>

int combination(int n, int r) {
  int ans;
  if (r == 0 || n == r) {
    ans = 1;
  } else if (r == 1) {
    ans = n;
  } else {
    ans = combination(n - 1, r - 1) + combination(n - 1, r);
  }
  return ans;
}

int main() {
  int n, r;
  printf("input n & r\n");
  printf("n : ");
  scanf("%d", &n);
  printf("r : ");
  scanf("%d", &r);
  printf("%dC%d is %d\n", n, r, combination(n, r));

  return 0;
}