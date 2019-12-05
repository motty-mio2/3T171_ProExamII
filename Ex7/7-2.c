#include <stdio.h>

typedef struct Tminmax {
  int min;
  int max;
} Tminmax;

Tminmax minmax(int ls[], int len) {
  Tminmax rt;
  rt.min = ls[0];
  rt.max = ls[0];
  for (int i = 1; i < len; i++) {
    if (ls[i] > rt.max) {
      rt.max = ls[i];
    } else if (ls[i] < rt.min) {
      rt.min = ls[i];
    }
  }

  return rt;
}

void printlist(int ls[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d  ", ls[i]);
  }
  putchar('\n');
}

int main() {
  int ls[] = {12, 43, 56, 3, 29};
  int len = 5;
  printlist(ls, len);
  Tminmax ts = minmax(ls, len);

  printf("max : %d\nmin : %d\n", ts.max, ts.min);

  return 0;
}