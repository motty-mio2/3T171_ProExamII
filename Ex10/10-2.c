#include <stdio.h>

int main() {
  int a, b, c, d, e, f;
  long x, y;

  printf("input 6 numbers\n");
  printf("  a -> ");
  scanf("%d", &a);
  printf("  b -> ");
  scanf("%d", &b);
  printf("  c -> ");
  scanf("%d", &c);
  printf("  d -> ");
  scanf("%d", &d);
  printf("  e -> ");
  scanf("%d", &e);
  printf("  f -> ");
  scanf("%d", &f);

  int tp = a * e - b * d;
  if (tp == 0) {
    printf("There is no solution\n");
  } else if ((d / a == e / b) && (e / b == f / c)) {
    printf("The solution forms a straight line.");
  } else {  //解あり
    x = (a * f - d * c) / tp;
    y = (c * e - b * f) / tp;
    printf("answer is \n");
    printf("  x is %ld\n", x);
    printf("  y is %ld\n", y);
  }

  return 0;
}

/*
解なし → 平行
直線 → 一致
解あり → 答え
*/