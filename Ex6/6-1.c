#include <stdio.h>

#define arrlong 200

void swap(int* a, int* b) {
  // implement this function
  int tp;
  tp = *a;
  *a = *b;
  *b = tp;
}

void initarr(int* a, long n) {  // init new (arr)a as (int)n
  for (int i = 0; i < arrlong; i++) {
    a[i] = n % 10;
    n /= 10;
  }
}

void printarr(int* a) {  // printout (arr)a
  int zeroc = 0;
  int tg;
  for (int i = arrlong - 1; i >= 0; i--) {
    tg = a[i];
    if (a[i] != 0 && zeroc == 0) {
      zeroc = 1;
    }
    if (zeroc == 1) {
      printf("%d", a[i]);
    }
  }
  printf("\n");
}

void addarr(int* a, int* b, int* c) {  // add two arrs (arr)a+(arr)b=(arr)c
  initarr(c, 0);
  int temp;
  for (int i = 0; i < arrlong; i++) {
    temp = (a[i] + b[i]);
    if ((i != arrlong - 1) && (temp > 9)) {
      c[i + 1] += 1;
    }
    c[i] += temp % 10;
  }
  // printf("%d\n", temp);
}

void multiarr(int* a, int* b, int* c) {  // multi two arrs (arr)a*(arr)b=(arr)c
  initarr(c, 0);
  int temp[arrlong];
  for (int i = 0; i < arrlong; i++) {
    if (a[i] != 0) {
      for (int j = 0; j < arrlong; j++) {
        if (b[j] != 0) {
          int calc = a[i] * b[j];
          int zs = i + j;
          int f = 0;
          while (calc > 0) {
            c[zs + f] += calc % 10;
            if (c[zs + f] > 9) {
              c[zs + f] -= 10;
              calc += 10;
            }
            calc /= 10;
            f++;
          }
        }
      }
    }
  }
}

void minusarr(int* a, int* b, int* c) {  // minus two arrs (arr)a-(arr)b=(arr)c
  initarr(c, 0);
  long temp = 0;
  for (int i = 0; i < arrlong; i++) {
    temp = a[i] - b[i];
    c[i] += temp;
    if (c[i] < 0) {
      c[i] += 10;
      c[i + 1] -= 1;
    }
  }
  // printf("%d\n", temp);
}

void factorial(int n, int* a) {  // calc n! = a
  initarr(a, 1);
  int temp[arrlong];
  int temp2[arrlong];
  for (int i = 2; i < n + 1; i++) {
    initarr(&temp, i);
    multiarr(a, &temp, &temp2);
    initarr(&temp, 0);
    addarr(&temp, &temp2, a);
  }
}

int main() {
  long n1 = 25;
  long n2 = 40;

  int A[arrlong];
  int B[arrlong];
  int C[arrlong];
  int D[arrlong];
  int E[arrlong];

  initarr(&A, n1);
  printf("array A is \t");
  printarr(&A);

  initarr(&B, n2);
  printf("array B is \t");
  printarr(&B);

  addarr(&A, &B, &C);
  printf("A + B is \t");
  printarr(&C);

  multiarr(&A, &B, &D);
  printf("A * B is \t");
  printarr(&D);

  minusarr(&A, &B, &E);
  printf("A - B is \t");
  printarr(&E);

  int ans1[arrlong];
  int ns = 100;
  factorial(ns, ans1);
  printf("%d! is \t", ns);
  printarr(&ans1);

  int ans2[arrlong];
  int fifties[arrlong];
  int nf = 50;
  factorial(nf, fifties);
  minusarr(&ans1, &fifties, &ans2);
  printf("%d! - %d! is \t", ns, nf);
  printarr(&ans2);

  return 0;
}