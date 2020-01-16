#include <stdio.h>
#include <string.h>

#define NUMS 100
int main() {
  FILE* fp1;
  FILE* fp2;
  fp1 = fopen("aaa.txt", "r");
  fp2 = fopen("bbb.txt", "w");

  char context[NUMS];

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

    char* tmp;
    while (fscanf(fp1, "%s", context) == 1) {
      tmp = strtok(context, " ");
      if (strstr(tmp, sta) != NULL) {  // include
        printf("%s ", sta);
        fprintf(fp2, "%s ", stb);
      } else {  // not include
        printf("%s ", tmp);
        fprintf(fp2, "%s ", tmp);
      }

      while (tmp != NULL) {
        tmp = strtok(NULL, "/");
        if (tmp != NULL) {
          if (strstr(tmp, sta) != NULL) {  // include
            printf("%s ", sta);
            fprintf(fp2, "%s ", stb);
          } else {  // not include
            printf("%s ", tmp);
            fprintf(fp2, "%s ", tmp);
          }
        }
      }

      /*
      printf("\n");
      fprintf(fp2, "\n");
      */
    }
  }

  fclose(fp1);
  fclose(fp2);

  return 0;
}