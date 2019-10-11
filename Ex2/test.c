#include <math.h>
#include <stdio.h>

int main() {
  int a = 0;
  for (long i = 1; i <= pow(2, 32) + 1; i++) {
    a = i;
    if (a <= 0) {
      printf("%ld\n", i);
    }
  }
}