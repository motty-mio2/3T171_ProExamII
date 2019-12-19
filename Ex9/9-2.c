/*
        身長と体重を読み込んで平均値を求めて表示する
*/

#include <stdio.h>

#define MEMBER 100

void copyarr(char from[MEMBER], char to[MEMBER]) {
  for (int i = 0; i < MEMBER; i++) {
    to[i] = from[i];
  }
}

void printarr(char a[MEMBER]) {
  for (int i = 0; i < MEMBER; i++) {
    printf("%c", a[i]);
  }
  printf("\n");
}

int main(void) {
  FILE *fp, *fp2;
  int ninzu = 0;               /* 人数 */
  char name[MEMBER][100] = {}; /* 名前 */
  double height[MEMBER] = {0};
  double weight[MEMBER] = {0}; /* 身長・体重 */
  char ntp[100];
  double htp, wtp;
  double hsum = 0.0; /* 身長の合計 */
  double wsum = 0.0; /* 体重の合計 */

  if ((fp = fopen("hw.dat", "r")) == NULL) /* オープン */
    printf("\aファイルをオープンできません。\n");
  else {
    while (fscanf(fp, "%s%lf%lf", ntp, &htp, &wtp) == 3) {
      // printf("%-10s %5.1f %5.1f\n", ntp, htp, wtp);
      ninzu++;
      int i = ninzu - 1;
      while ((htp > height[i - 1]) && (i > 0)) {
        copyarr(name[i - 1], name[i]);
        height[i] = height[i - 1];
        weight[i] = weight[i - 1];
        i--;
      }
      // printf("%s ", ntp);
      copyarr(ntp, name[i]);
      height[i] = htp;
      weight[i] = wtp;
      // printf("%s ", ntp);
      /*
            for (int i = 0; i < ninzu; i++) {
              printf("%s ", name[i]);
            }
            printf("\n");*/
    }
  }
  fclose(fp); /* クローズ */

  fp2 = fopen("hw2.dat", "w");
  for (int i = 0; i < ninzu; i++) {
    fprintf(fp2, "%s %.1f %.1f\n", name[i], height[i], weight[i]);
    printf("%s\t%.1f\t%.1f\n", name[i], height[i], weight[i]);
    // printf("%f ", weight[i]);
  }

  fclose(fp2);
  return 0;
}
