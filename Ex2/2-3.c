#include <math.h>
#include <stdio.h>

unsigned set(unsigned int x, unsigned int pos) {
  unsigned int tmp, ans;
  tmp = (1U << (pos - 1));
  ans = tmp | x;
  return ans;
}

unsigned reset(unsigned int x, unsigned int pos) {
  unsigned int tmp, ans;
  tmp = ~(1U << (pos - 1));
  ans = tmp & x;
  return ans;
}

unsigned inverse(unsigned int x, unsigned int pos) {
  unsigned int tmp, tmp2, ans;
  tmp = (1U << (pos - 1));
  tmp2 = (tmp & x);
  if (tmp2 > 0) {  // target is 1, set to 0
    ans = set(x, pos);
  } else {  // target is 0, set to 1
    ans = reset(x, pos);
  }
  return ans;
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

int main() {
  unsigned int x, pos;

  printf("input x\t:");
  scanf("%d", &x);
  printf("pos\t:");

  scanf("%d", &pos);
  printf("input\t:");
  print_bits(x);

  printf("set\t:");
  print_bits(set(x, pos));
  printf("reset\t:");
  print_bits(reset(x, pos));
  printf("inverse\t:");
  print_bits(inverse(x, pos));

  return 0;
}
