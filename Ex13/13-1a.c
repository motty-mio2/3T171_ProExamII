#include <stdio.h>

#define NUMS 100

int finder(char a[NUMS], int st, int ed) {
  int chk = 0;
  int len = ed - st + 1;
  while ((a[st + chk] == a[ed - chk]) && (chk < len / 2)) {
    chk++;
  }
  int rt;
  if (chk == len / 2) {
    rt = len;
  } else {
    rt = 0;
  }
  return rt;
}

void printcarr(char a[NUMS], int st, int ed) {
  for (int i = st; i < ed + 1; i++) {
    putchar(a[i]);
  }
  printf("\t");
  // printf("  ");
}

int main() {
  char ins[NUMS] = {' '};
  char tp;
  int ct = 0;
  while ((tp = getchar()) != '\n') {
    ins[ct] = tp;
    ct += 1;
  }
  // printcarr(ins, 0, ct);
  // printf("\n");
  int pat[2] = {0, 0};
  int max = 0;
  for (int i = 0; i < ct - 1; i++) {
    for (int j = i + 1; j < ct; j++) {
      // printcarr(ins, i, j);
      int ans = finder(ins, i, j);
      // printf("%d\n", ans);
      if (ans > max) {
        pat[0] = i;
        pat[1] = j;
        max = ans;
      }
    }
  }
  if (pat[0] == pat[1]) {
    printf("No Ans\n");
  } else {
    printcarr(ins, pat[0], pat[1]);
    printf("\n");
  }
  return 0;
}