#include <stdio.h>

int main() {
  int a = 3;
  int b = 4;
  for (int i = 0; i < b; i++) {
    a++;
    if (a % 3 == 0) {
      i -= 1;
      b += 1;
    }
    printf("%d %d %d\n", a, b, i);
  }
  return 0;
}