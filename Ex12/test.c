#include <stdio.h>
#define NUMS 3

void printarr(int a[NUMS], int ed) {
  for (int i = 0; i < ed; i++) {
    printf("%d, ", a[i]);
  }
  printf("\n");
}

void printcarr(char a[NUMS], int ed) {
  for (int i = 0; i < ed; i++) {
    putchar(a[i]);
  }
  printf("\n");
}

void lshif_int(int a[NUMS], int tp) {
  for (int i = tp; i < NUMS - 1; i++) {
    a[i] = a[i + 1];
  }
  a[NUMS - 1] = 0;
}

void lshif_char(char a[NUMS], int tp) {
  for (int i = tp; i < NUMS - 1; i++) {
    a[i] = a[i + 1];
  }
  a[NUMS - 1] = 'a';
}

void adder(int a[NUMS], char f[NUMS], int ms) {
  a[ms] += a[ms + 1];
  lshif_char(f, ms);
  lshif_int(a, ms + 1);
}

void miner(int a[NUMS], char f[NUMS], int ms) {
  a[ms] -= a[ms + 1];
  lshif_char(f, ms);
  lshif_int(a, ms + 1);
}
void multi(int a[NUMS], char f[NUMS], int ms) {
  a[ms] *= a[ms + 1];
  lshif_char(f, ms);
  lshif_int(a, ms + 1);
}

int main() {
  int a[NUMS] = {1, 2, 3};
  char b[NUMS] = {'+', '-', ' '};
  printarr(a, NUMS);
  printcarr(b, NUMS);
  adder(a, b, 0);
  printarr(a, NUMS);
  printcarr(b, NUMS);

  return 0;
}