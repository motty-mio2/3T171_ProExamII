#include <stdio.h>

int eukleides(int a, int b) {
  int rem = a % b;
  while (rem != 0) {
    a = b;
    b = rem;
    rem = a % b;
  }

  return b;
}

int main() {
  int a, b;
  printf("input 2 numbers\n");
  printf("  1st : ");
  scanf("%d", &a);
  printf("  2nd : ");
  scanf("%d", &b);
  int ans;
  if (a > b) {
    ans = eukleides(a, b);
  } else {
    ans = eukleides(b, a);
  }

  printf("GCD is %d\n", ans);
  return 0;
}