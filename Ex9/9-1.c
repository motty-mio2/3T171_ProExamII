#include <stdio.h>

int main() {
  FILE* fp;
  FILE* fp2;
  fp = fopen("hw.txt", "r");
  fp2 = fopen("~/hw2.txt", "w");

  char context[100];
  int height;
  float weight;

  if (fp == NULL) {
    // printf("\aファイル\"hw\"をオープンできませんでした。\n");
  } else {
    // printf("\aファイル\"hw\"をオープンしました。\n");
    while (fscanf(fp, "%s %d %f", context, &height, &weight) == 3) {
      printf("%s %d %.1f\n", context, height, weight);
      fprintf(fp2, "%s %d %.1f\n", context, height, weight);
    }

    fclose(fp);
  }
  return 0;
}