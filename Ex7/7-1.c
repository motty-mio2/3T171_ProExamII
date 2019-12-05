#include <stdio.h>

#define NUMBER 5

typedef struct {
  int num;
  int eng;
  int math;
  int sum;
} student;

void printscore(student v[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\n", v[i].num, v[i].sum, v[i].eng, v[i].math);
  }
}

void swapst(student* x, student* y) {
  student tp = *x;
  *x = *y;
  *y = tp;
}

void sortst(student v[], int n) {
  int i, j;

  for (i = 0; i < n - 1; i++) {
    for (j = n - i; j > i; j--) {
      if (v[j].sum > v[j - 1].sum) {
        swapst(&v[j], &v[j - 1]);
      }
    }
  }
}

int main(void) {
  int i;
  student st[NUMBER];

  printf("%d人の点数を入力してくださいB\n", NUMBER);
  for (i = 0; i < NUMBER; i++) {
    st[i].num = i + 1;
    printf("[%d] 英語 数学 : ", i + 1);
    scanf("%d %d", &st[i].eng, &st[i].math);
    st[i].sum = st[i].eng + st[i].math;
  }

  printf("Number\tSum\tEnglish\tMath\n");
  for (i = 0; i < NUMBER; i++) {
    sortst(st, NUMBER);
  }

  printscore(st, NUMBER);

  return 0;
}
