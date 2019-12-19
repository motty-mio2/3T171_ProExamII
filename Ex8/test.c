#include <stdio.h>

#define NUMS 10

void printlist(int a[], int ls) {
  for (int i = 0; i < ls; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int part[NUMS];
  int last, i;
  char tp;
  for (i = 0; i < NUMS; i++) {
    scanf("%c", &tp);
    if (tp == "\n") {
      last = i - 1;
      break;
    } else {
      last = i;
      part[i] = tp - '0';
    }
  }
  printlist(part, last);
}