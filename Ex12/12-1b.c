#include <stdio.h>

#define NUMS 100

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
  lshif_int(a, ms + 1);
  lshif_char(f, ms);
}

void miner(int a[NUMS], char f[NUMS], int ms) {
  a[ms] -= a[ms + 1];
  lshif_int(a, ms + 1);
  lshif_char(f, ms);
}

void multi(int a[NUMS], char f[NUMS], int ms) {
  a[ms] *= a[ms + 1];
  lshif_int(a, ms + 1);
  lshif_char(f, ms);
}

int maincalu() {
  int numbers[NUMS] = {0};
  char funcs[NUMS] = {' '};
  char tp;
  int ep_n = 0, ep_f = 0;
  int tn = 0;
  for (int i = 0; i < NUMS; i++) {
    tp = getchar();
    if (tp == '(') {
      tn = maincalu();
    } else if (tp == '\n' || tp == ')') {
      numbers[ep_n] = tn;
      ep_n++;
      break;
    } else if (tp == '+' || tp == '-' || tp == '*') {
      funcs[ep_f] = tp;
      numbers[ep_n] = tn;
      tn = 0;
      ep_f++;
      ep_n++;
    } else if (tp != ' ') {
      tn = tn * 10 + (tp - '0');
    }
  }
  // printarr(numbers, ep_n);
  int endpointl = ep_f;
  int i = 0;
  while (i < endpointl) {  //掛け算
    if (funcs[i] == '*') {
      multi(numbers, funcs, i);
      ep_f--;
    } else {
      i++;
    }
  }

  for (int i = 0; i < ep_f; i++) {  //足し引き算
    if (funcs[i] == '+') {
      adder(numbers, funcs, i);
      i--;
    }
    if (funcs[i] == '-') {
      miner(numbers, funcs, i);
      i--;
    }
  }
  return numbers[0];
}

int main() {
  int ans = maincalu();

  printf("\n");
  printf("%d", ans);

  return 0;
}