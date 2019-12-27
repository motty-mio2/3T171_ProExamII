#include <stdio.h>

#define NUMS 100

void print_integer(int number) {
  // print
  int pout[NUMS];
  int i = 0;
  do {
    pout[i] = number % 10;
    number /= 10;
    i++;
    //    printf("i is %d\n", i);
  } while (number > 0);
  for (int j = i - 1; j >= 0; j--) {
    char tp = pout[j] + '0';
    putchar(tp);
  }
  putchar('\n');
}

int main() {
  int a;
  printf("input number --> ");
  scanf("%d", &a);

  print_integer(a);
  return 0;
}