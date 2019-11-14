#include <stdio.h>

#define DISHES 5

void printlist(int a[]) {
  for (int i = 0; i < DISHES; i++) {
    printf("%d", a[i]);
    printf(" ");
  }
  printf("\n");
}

int calc(int order[], int price[]) {
  int sum = 0;
  for (int i = 0; i < DISHES; i++) {
    sum += order[i] * price[i];
  }
  return sum;
}

void initorder(int order[], int n) {
  for (int i = 0; i < n; i++) {
    order[i] = 0;
  }
  order[n] = 0;
  for (int i = n + 1; i < DISHES; i++) {
    order[i] = 0;
  }
}

void clearorder(int order[], int n) {  // n番以降を初期化
  for (int i = n; i < DISHES; i++) {
    order[i] = 0;
  }
}

int tracking(int order[], int price[], int n) {
  order[n] = 1;
  int getrt;
  int money = calc(order, price);
  // printf("%d\t", money);
  // printlist(order); // No.1
  if (money == 30000) {
    // printf("here is 30000\n");
    return 0;  // return -1
  } else if (n != DISHES - 1) {
    for (int i = n + 1; i < DISHES; i++) {
      getrt = tracking(order, price, i);
      if (getrt == 0) {
        return 0;
      } else {
        clearorder(order, i);
      }  // clearorder(order, i); //No.2
    }
  } else {
    return -1;
  }
}

int main() {
  int price[] = {10000, 7700, 15200, 8200, 7100};
  int order[5];
  int rt;
  for (int i = 0; i < DISHES; i++) {
    initorder(order, i);
    rt = tracking(order, price, i);
    // printf("\t%d\n", rt);
    if (rt == 0) {
      break;
    }
  }

  printf("order list tag : ");
  printlist(order);
  printf("sum price is  %d\n", calc(order, price));

  return 0;
}
