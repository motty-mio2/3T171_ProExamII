#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

/* 補助関数: 実行時間を測定するための関数 */
double getcputime(void) {
  struct rusage use;
  getrusage(RUSAGE_SELF, &use);
  return (double)use.ru_utime.tv_sec + (double)use.ru_utime.tv_usec * 0.000001;
}

int main(void) {
  double start, end;
  /*変数代入など*/

  /* 開始時間 */
  start = getcputime();
  /* 終了時間 */

  end = getcputime();

  printf("time: %f [s]\n", end - start);

  return 0;
}
