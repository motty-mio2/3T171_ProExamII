#include <stdio.h>

int main() {
  unsigned int n;
  printf("input nature number n\n  --> ");
  scanf("%d", &n);

  int ans = 2 * n + 1;  // at x axis
  // int ans = 0;

  for (int i = 1; i < n + 1; i++) {  // y axis
    // printf("y = %d  ", i);
    int tmp = 0;
    for (int j = 1; j < n + 1; j++) {  // x number
      if (n * n > i * i + j * j) {
        tmp += 1;
      } else {
        break;
      }
    }
    ans += 2 + 4 * tmp;
    // printf("answer is %d\n", ans);
  }

  printf("answer is %d\n", ans);

  return 0;
}