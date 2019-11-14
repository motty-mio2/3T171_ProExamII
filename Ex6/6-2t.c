#include <stdio.h>

#define DISHES 5

void printlist(int* a) {
  for (int i = 0; i < DISHES; i++) {
    printf("%d", a[i]);
    printf(" ");
  }
  printf("\n");
}

int calc(int* order, int* price) {
  int sum = 0;
  for (int i = 0; i < DISHES; i++) {
    sum += order[i] * price[i];
  }
  return sum;
}

void initorder(int* order, int n) {
  for (int i = 0; i < n; i++) {
    order[i] = 0;
  }
  order[n] = 0;
  for (int i = n + 1; i < DISHES; i++) {
    order[i] = 0;
  }
}

int tracking(int* order, int* price, int n) {
  order[n] = 1;
  int money = calc(order, price);
  printf("%d\t", money);
  printlist(order);

  if (money > 30000) {
    // printf("over 30000\n");
    order[n] = 0;
    return 1;
  } else if (money == 30000) {
    // printf("here is 30000\n");
    return 0;
  } else {  // price < 30000
    int get = -1;
    for (int i = n + 1; i < DISHES; i++) {
      get = tracking(order, price, i);
      if (get != -1) {
        break;
      }
    }
  }
}

int main() {
  int price[] = {10000, 7700, 15200, 8200, 7100};
  int order[5];
  for (int i = 0; i < DISHES; i++) {
    initorder(&order, i);
    tracking(&order, &price, i);
  }
  return 0;
}