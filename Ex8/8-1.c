#include <stdio.h>

#define NUMS 100

void printwordarr(char* text[]) {
  for (int i = 0; i < NUMS; i++) {
    printf("%s", text[i]);
  }
  printf("\n");
}

void printarr(int a[]) {  // printout (arr)a
  for (int i = 0; i < NUMS; i++) {
    printf("%d", a[i]);
  }
  printf("\n");
}

void word2num(char* text, int* convnum) {
  for (int i = 0; i < NUMS; i++) {
    convnum[i] = text[i] - 0;
  }
}

void num2word(int* convnum, char* text) {
  for (int i = 0; i < NUMS; i++) {
    convnum[i] = text[i];
  }
}
void encrypt(char* plain, char* clipher, int rshift) {
  int temp[NUMS];
  word2num(&plain, &temp);
  for (int i = 0; i < NUMS; i++) {
    int tp = temp[i];
    if (64 < tp, tp < 91) {
      clipher = ((tp - 65) + rshift) % 26 + 65;
    }
  }
  num2word(&temp, &clipher);
}

void decrypt() {}

int main() {
  char intext[NUMS];
  char outtext[NUMS];
  int rshift;
  printf("input text -> ");
  fgets(intext, NUMS, stdin);
  printf("input encyrpt keys -> ");
  scanf("%d", &rshift);

  printf("%s", intext);

  /*  encrypt(intext, outtext, rshift);

    printwordarr(intext);

    printwordarr(outtext);
  */
  return 0;
}