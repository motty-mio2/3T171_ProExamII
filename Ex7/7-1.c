#include <stdio.h>

#define NUMBER 5

struct student {
  int eng;
  int math;
  int sum;
};

void printscore(struct student v[], int fl) {
  printf("%d\t%d\t%d\t%d\n", fl, v[fl].sum, v[fl].eng, v[fl].math);
}

int max_of(struct student v[], int n, int sc) {
  int i;
  int fl;

  if (sc == 0) {
    fl = 0;
    for (i = 1; i < n; i++) {
      if (v[i].sum > v[fl].sum) {
        fl = i;
      }
    }
  } else {
    fl = 0;
    for (i = 0; i < n; i++) {
      if (v[fl].sum < v[i].sum && v[i].sum < sc) {
        fl = i;
      }
    }
  }

  printscore(v, fl);

  return v[fl].sum;
}

int main(void) {
  int i;

  struct student st[NUMBER];

  printf("%d人の点数を入力してくださいB\n", NUMBER);
  for (i = 0; i < NUMBER; i++) {
    printf("[%d] 英語 数学 : ", i + 1);
    scanf("%d %d", &st[i].eng, &st[i].math);
    st[i].sum = st[i].eng + st[i].math;
  }

  int sc = 0;
  printf("Number\tSum\tEnglish\tMath\n");
  for (i = 0; i < NUMBER; i++) {
    sc = max_of(st, NUMBER, sc);
  }

  return 0;
}
