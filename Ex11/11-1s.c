#include <stdio.h>
#include <string.h>

#define NUMS 100
int main() {
  FILE* fp1;
  FILE* fp2;
  fp1 = fopen("aaa.txt", "r");
  fp2 = fopen("bbb.txt", "w");

  if (fp1 == NULL) {
    printf("Cannot open file aaa.txt\n");
  } else {
    // printf("\aファイル\"hw\"をオープンしました。\n");
    char sta[NUMS], stb[NUMS];
    printf("input 2 words\n");
    printf("  1st : ");
    scanf("%s", sta);
    printf("  2nd : ");
    scanf("%s", stb);

    int chs;                                // 文字数
    for (chs = 0; sta[chs] != '\0'; ++chs)  // sta の文字数数え上げ
      ;

    int tp;           // ファイルの文字
    int flag = 0;     // 文字一致判定
    int sp = 0;       //空白・改行からの文字数
    int queue[NUMS];  //空白・改行までの入力文字

    while ((tp = fgetc(fp1)) != EOF) {
      if (tp == ' ' || tp == '\n') {  // 文節判断部
        if (flag >= chs) {            // 置換条件を満たす
          fprintf(fp2, "%s", stb);
          printf("%s", stb);
        } else {
          for (int i = 0; i < sp; i++) {
            fputc(queue[i], fp2);
            putchar(queue[i]);
          }
        }
        sp = 0;
        flag = 0;
        fputc(tp, fp2);
        putchar(tp);
      } else {
        queue[sp] = tp;
        sp++;
        if (tp == sta[flag]) {  // 内容の1文字一致
          flag++;
        } else if (flag < chs) {  //不一致かつ置換条件を満たさない
          flag = 0;
        }
      }
    }
    if (sp != 0) {
      if (flag >= chs) {  // 置換条件を満たす
        fprintf(fp2, "%s", stb);
        printf("%s", stb);
      } else {
        for (int i = 0; i < sp; i++) {
          fputc(queue[i], fp2);
          putchar(queue[i]);
        }
      }
    }
  }

  fclose(fp1);
  fclose(fp2);

  return 0;
}