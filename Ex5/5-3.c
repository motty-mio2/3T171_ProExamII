#include <stdio.h>

void del_digit(char arr[], int length) {
  for (int i = 0; i < length; i++) {
    char temp = (arr[i]);
    if (temp < 48 || temp > 57) {
      putchar(temp);
    }
  }
}

void str_chnum() {}

int main() {
  char ch[] = {'a', 'B', '0', '+', '*', '9', '@'};
  del_digit(ch, sizeof(ch));
  printf("\n");

  return 0;
}