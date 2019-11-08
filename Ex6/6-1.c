#include <stdio.h>

#define arrlong 200

long long power(int x, int n) {  // x^n
  long ans = 1;
  if (n == 0 || x == 0) {
    ans = 1;
  } else {
    for (int i = 0; i < n; i++) {
      ans *= x;
    }
  }
  return ans;
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
      c[i + 1] += 1
    }
    c[i] += temp % 10;
  }
  // printf("%d\n", temp);
  initarr(c, temp);
}

void multiarr(int* a, int* b, int* c) {  // multi two arrs (arr)a*(arr)b=(arr)c
  initarr(c, 0);
  int temp[arrlong];
  long calc;
  for (int i = 0; i < arrlong; i++) {
    for (int j = 0; j < arrlong; j++) {
      calc = a[i] * b[j] * power(10, i) * power(10, j);
      initarr(temp, calc);
      addarr(c, &temp, c);
    }
  }
}

void minusarr(int* a, int* b, int* c) {  // minus two arrs (arr)a-(arr)b=(arr)c
  long temp = 0;
  for (int i = 0; i < arrlong; i++) {
    temp += (a[i] - b[i]) * power(10, i);
  }
  // printf("%d\n", temp);
  initarr(c, temp);
}

int main() {
  long n1 = 10;
  long n2 = 15;

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
  printf("A + B is \t");
  printarr(&E);

  int ans1[arrlong];
  initarr(&ans1, 1);
  int fiftys[arrlong];
  initarr(&fiftys, 0);
  int temp[arrlong];
  for (int i = 1; i < 10; i++) {
    initarr(&temp, i);
    multiarr(&ans1, &temp, &ans1);
    if (i == 50) {
      addarr(&fiftys, &temp, &fiftys);
    }
  }
  printf("100! is \t");
  printarr(&ans1);
  /*
    printf("100! -50! is \t");
    int ans2[arrlong];
    minusarr(&ans1, &fiftys, &ans2);
    printarr(&ans2);
    */

  return 0;
}