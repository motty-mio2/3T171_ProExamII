#include <stdio.h>

void swap(int* a, int* b) {
  // implement this function
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void sort3(int* a, int* b, int* c) {
  if (*a > *b) {
    swap(a, b);
  }
  if (*a > *c) {
    swap(a, c);
  }
  if (*b > *c) {
    swap(b, c);
  }
}

int main() {
  int n1, n2, n3;

  printf("input numbers\n");
  printf("  Number1 :");
  scanf("%d", &n1);
  printf("  Number2 :");
  scanf("%d", &n2);
  printf("  Number3 :");
  scanf("%d", &n3);

  //  printf("You input\n  1:%d\n  2:%d\n  3:%d\n", n1, n2, n3);
  sort3(&n1, &n2, &n3);
  printf("Sorted\n  1:%d\n  2:%d\n  3:%d\n", n1, n2, n3);

  return 0;
}