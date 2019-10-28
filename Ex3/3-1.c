#include <stdio.h>

#define DATAS 5

/*
void sortby(int fig, int listf[2][DATAS], int listt[2][DATAS]) {
  int ano = (fig + 1) % 2;
  for (int i = 0; i < DATAS; i++) {  // iは対象
    int temp = listf[fig][i];
    int pos = i;
    for (int j = i + 1; j < DATAS; j++) {  // jは最小
      if (temp > listf[fig][j]) {
        temp = listf[fig][j];
        pos = j;
      }
    }
    // 最小値とiを入れ替え
    for (int k = 0; k < 2; k++) {
      listf[k][pos] = listf[k][i];
    }

    listt[fig][i] = temp;
    listt[ano][i] = listf[ano][pos];
    printlist(listt);
    printf("\n");
  }
}
*/

void sortbyx(int fig, int list[2][DATAS]) {
  int ano = (fig + 1) % 2;
  int temp[2];
  for (int i = 0; i < DATAS; i++) {  // iは対象
    temp[fig] = list[fig][i];
    temp[ano] = list[ano][i];
    int pos = i;
    for (int j = i + 1; j < DATAS; j++) {  // jは最小
      if (temp[fig] > list[fig][j]) {
        temp[fig] = list[fig][j];
        temp[ano] = list[ano][j];
        pos = j;
      }
    }
    // 最小値とiを入れ替え
    for (int k = 0; k < 2; k++) {
      list[k][pos] = list[k][i];
    }

    list[fig][i] = temp[fig];
    list[ano][i] = temp[ano];
  }
}

void printlist(int list[2][DATAS]) {
  printf("No.\tHeight\tWeight\n");
  for (int i = 0; i < DATAS; i++) {
    printf("%d\t%d\t%d\n", i + 1, list[0][i], list[1][i]);
  }
  return;
}

int main() {
  int health[2][DATAS];

  printf("%d人の身長を入力してください。\n", DATAS);
  for (int j = 0; j < DATAS; j++) {
    printf("  %d番：", j + 1);
    scanf("%d", &health[0][j]);
  }

  printf("%d人の体重を入力してください。\n", DATAS);
  for (int j = 0; j < DATAS; j++) {
    printf("  %d番：", j + 1);
    scanf("%d", &health[1][j]);
  }
  printf("\n");
  printlist(health);

  // int data1[2][DATAS];

  printf("========================\n   sort by height\n");
  sortbyx(0, health);
  printlist(health);

  printf("========================\n   sort by weight\n");
  sortbyx(1, health);
  printlist(health);

  // int data2[2][DATAS];
  // sortby(1, health);

  /*
  printlist(data1);
  */
  /*
     printf("====================\n\tsort by weight\n");
     printlist(data2);
   */
  return 0;
}