#include <stdio.h>

int calcsum(int* price, int* order) {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += price[i] * order[i];
  }

  return sum;
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
  int order[5] = {1, 0, 0, 0, 0};
  int flag = 0;  // 0 : lower 30000, 1 : 30000, 2 : higher 30000
  int price;

  price = calcsum(&p_list, &order);
  printorder(&order);

  for (int i = 1; i >= 0; i--) {
    order[0] = i;
    price = calcsum(&p_list, &order);
    if (price == 30000) {
      goto fin;
    } else if (price > 30000) {
      continue;
    } else {
      // printorder(&order);
      for (int j = 0; j < 2; j++) {
        order[1] = j;
        price = calcsum(&p_list, &order);
        if (price == 30000) {
          goto fin;
        } else if (price > 30000) {
          continue;
        } else {
          // printorder(&order);
          for (int k = 0; k < 2; k++) {
            order[2] = k;
            price = calcsum(&p_list, &order);
            if (price == 30000) {
              goto fin;
            } else if (price > 30000) {
              continue;
            } else {
              // printorder(&order);
              for (int l = 0; l < 2; l++) {
                order[3] = l;
                price = calcsum(&p_list, &order);
                if (price == 30000) {
                  goto fin;
                } else if (price > 30000) {
                  continue;
                } else {
                  // printorder(&order);
                  for (int m = 0; m < 2; m++) {
                    order[4] = m;
                    price = calcsum(&p_list, &order);
                    if (price == 30000) {
                      goto fin;
                    } else if (price > 30000) {
                      continue;
                    }
                    printorder(&order);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
fin:
  printf("exit loop\n");
  printorder(&order);
  return 0;
}