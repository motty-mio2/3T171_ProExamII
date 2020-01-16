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

void maincalu(int numbers[NUMS],
              char funcs[NUMS],
              int startpoint,
              int endpoint) {
  int endpointl = endpoint;
  int i = startpoint;
  while (i < endpointl) {  //掛け算
    // putchar(funcs[i]);
    // putchar('\n');
    if (funcs[i] == '*') {
      multi(numbers, funcs, i);
      endpoint--;
    } else {
      i++;
    }
  }
  /*
  printarr(numbers, endpoint);
  printcarr(funcs, endpoint);
  */
  for (int i = startpoint; i < endpoint; i++) {  //足し引き算
    if (funcs[i] == '+') {
      adder(numbers, funcs, i);
      i--;
    }
    if (funcs[i] == '-') {
      miner(numbers, funcs, i);
      i--;
    }
  }
}

int main() {
  int ns[NUMS] = {0};
  char fs[NUMS] = {' '};
  char tp;
  int endpoint = 0;
  int tn = 0;
  for (int i = 0; i < NUMS; i++) {
    tp = getchar();
    if (tp != '+' && tp != '-' && tp != '*' && tp != '(' && tp != ')' &&
        tp != '\n' && tp != ' ') {
      tn = tn * 10 + (tp - '0');
    } else if (tp == '+' || tp != '-' || tp != '*' || tp != '(' || tp != ')') {
      fs[endpoint] = tp;
      ns[endpoint] = tn;
      tn = 0;
      // printf("%d %c ", ns[endpoint], fs[endpoint]);
      endpoint++;
    }
    if (tp == '\n') {
      break;
    }
  }

  // printf("\n");
  // printcarr(fs, endpoint);
  maincalu(ns, fs, 0, endpoint);
  printf("%d", ns[0]);

  return 0;
}