#include <stdio.h>

#define NUMS 100

void encrypt(char plain[NUMS], char clipher[NUMS], int rshift) {
  int i = 0;
  char tp;
  while (1) {
    tp = plain[i];
    // printf("%d\n", plain[i]);
    if ((tp - 0) == 0) {
      clipher[i] = '\n';
      break;
    } else if ('A' <= tp && tp <= 'Z') {
      clipher[i] = ((tp - 'A') + rshift + 26) % 26 + 'A';
    } else if ('a' <= tp && tp <= 'z') {
      clipher[i] = ((tp - 'a') + rshift + 26) % 26 + 'a';
    } else {
      clipher[i] = tp;
    }
    printf("%c", clipher[i]);
    i++;
  }
  printf("\n");
}
/*
void decrypt(char plain[NUMS], char clipher[NUMS], int rshift) {
  int i = 0;
  char tp;
  while (1) {
    tp = plain[i];
    // printf("%d\n", plain[i]);
    if ((tp - 0) == 0) {
      clipher[i] = '\n';
      break;
    } else if ('A' <= tp && tp <= 'Z') {
      clipher[i] = ((tp - 'A') - rshift + 26) % 26 + 'A';
    } else if ('a' <= tp && tp <= 'z') {
      clipher[i] = ((tp - 'a') - rshift + 26) % 26 + 'a';
    } else {
      clipher[i] = tp;
    }
    printf("%c", clipher[i]);
    i++;
  }
  printf("\n");
}
*/

void decrypt2(char plain[NUMS], char clipher[NUMS], int rshift) {
  encrypt(plain, clipher, -1 * rshift);
}

int main() {
  char tp;
  char c[NUMS] = {0};
  char out1[NUMS], out2[NUMS];
  int rshift = 1;
  int last = 0;

  printf("input key -> ");
  scanf("%d", &rshift);
  scanf("%c", &tp);
  printf("input text -> ");

  while ((tp = getchar()) != '\n') {
    c[last] = tp;

    printf("%c", c[last]);
    last++;
  }
  printf("\n");
  encrypt(c, out1, rshift);
  decrypt2(out1, out2, rshift);
  // printf("%s\n", out1);
  return 0;
}