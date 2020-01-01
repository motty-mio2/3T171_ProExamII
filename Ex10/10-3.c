#include <stdio.h>

long mpow(int a) {
  return a * a;
}

int main() {
  int xs[6], ys[6];
  printf("input 6 numbers\n");
  printf("  a-x -> ");
  scanf("%d", &xs[0]);
  printf("  a-y -> ");
  scanf("%d", &ys[0]);
  printf("  b-x -> ");
  scanf("%d", &xs[1]);
  printf("  b-y -> ");
  scanf("%d", &ys[1]);
  printf("  c-x -> ");
  scanf("%d", &xs[2]);
  printf("  c-y -> ");
  scanf("%d", &ys[2]);

  long len[3];
  double vec = 0.0;
  if (ys[1] != ys[0]) {
    vec = (xs[1] - xs[0]) / (ys[1] - ys[0]);
  }

  for (int i = 1; i < 4; i++) {
    len[i - 1] = mpow(xs[i] - xs[(i + 1) % 3]) + mpow(ys[i] - ys[(i + 1) % 3]);
    printf("len%d is %ld\n", i - 1, len[i - 1]);
  }

  if ((xs[2] - xs[0]) * vec == ys[2] - ys[0]) {  // 1直線
    printf("Three points are on a straight line");
  } else if (len[0] + len[1] == len[2] || len[1] + len[2] == len[0] ||
             len[2] + len[0] == len[1]) {  //直角三角形
    printf("Three points forms a Right triangle");
  } else if (len[0] + len[1] > len[2] && len[1] + len[2] > len[0] &&
             len[2] + len[0] > len[1]) {  //鋭角三角形
    printf("Three points forms an Acute triangle");
  } else if (len[0] + len[1] < len[2] || len[1] + len[2] < len[0] ||
             len[2] + len[0] < len[1]) {  //鈍角三角形
    printf("Three points forms an Obtuse triangle");
  } else {
    printf("Exceptin");
  }
  printf("\n");

  return 0;
}