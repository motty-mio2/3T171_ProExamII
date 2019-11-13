#include <stdio.h>

int calcsum(int* price, int* order) {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += price[i] * order[i];
  }
  return sum;
}

int searchdish(int target_dish, int* p_list, int* order) {
  order[target_dish] = 1;
  int price = calcsum(p_list, order);
  if (price > 30000) {
    order[target_dish] = 0;
    return 1;
  } else if (price == 30000) {
    return 0;
  } else {  // price < 30000
    return -1;
  }
}

void printorder(int* order) {
  // for (int i = 0; i < 5; i++) {
  printf("order is ");
  printf("%d\t%d\t%d\t%d\t%d\n", order[0], order[1], order[2], order[3],
         order[4]);
  //}
}

int main() {
  int p_list[] = {10000, 17700, 15200, 8200, 7100};
  int order[5] = {0, 0, 0, 0, 0};
  int flag = 0;
  int result;
  for (int i = 0; i < 5; i++) {
    result = searchdish(i, &p_list, &order);
    if (result == -1) {
      result = searchdish(1, &p_list, &order);
    } else if (result == 0) {
      break;
    } else {  // result == 1
    }
    printorder(&order);
  }

  return 0;
}