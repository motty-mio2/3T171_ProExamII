#include <math.h>
#include <stdio.h>

int main() {
  unsigned int x, n;

  printf("input x:");
  scanf("%d", &x);
  printf("input n:");
  scanf("%d", &n);
  printf("input\t:");
  print_bits(x);
  // printf("rrotate\n");
  printf("rrotate\t:");
  print_bits(rrotate(x, n));
  // printf("lrotate\n");
  printf("lrotate\t:");
  print_bits(lrotate(x, n));
  return 0;
}

int count_bits(unsigned int x) {
  int bits = 0;
  while (x) {
    if (x & 1U)
      bits++;
    x >>= 1;
  }
  return bits;
}

int int_bits(void) {
  return count_bits(~0U);
}

int print_bits(unsigned int x) {
  int i;
  for (i = int_bits() - 1; i >= 0; i--) {
    putchar(((x >> i) & 1U) ? '1' : '0');
  }
  printf("\n");
}

int rrotate(unsigned int x, unsigned int n) {
  return lrotate(x, int_bits() - n);
  // xls >> ;
  // return x;
}

int lrotate(unsigned int x, unsigned int n) {
  unsigned int ans;
  unsigned int t_low, t_high;
  // printf("%d", int_bits());
  t_high = (x >> int_bits() - n);
  t_low = x << n;
  /*
  printf("\nt_high\t:");
  print_bits(t_high);
  printf("t_low\t:");
  print_bits(t_low);
  */
  ans = t_high | t_low;
  // ans = temp | x >> n;
  return ans;
}
