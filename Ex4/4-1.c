#include <stdio.h>

void swap(int* a, int* b) {
  // implement this function

  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  enum { INIT_X = 3, INIT_Y = 5 };

  int x = INIT_X, y = INIT_Y;

  swap(&x, &y);

  if (x == INIT_Y && y == INIT_X)
    printf("OK!\n");
  else {
    printf("Try again!\n");
    printf("Initial values are (%d, %d)\n", INIT_X, INIT_Y);
    printf("Therefore swapped results should be (%d, %d)\n", INIT_Y, INIT_X);
    printf("But my swapped values are (%d, %d)\n", x, y);
  }
  return 0;
}
