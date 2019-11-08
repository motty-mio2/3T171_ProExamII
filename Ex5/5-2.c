#include <stdio.h>

void print_char_arr(char arr[], int length) {
  for (int i = 0; i < length; i++)
    putchar(arr[i]);
}
/*
void input_mode() {
  char ch[100];
  printf("input charas");
  scanf("%s", ch);

  // printf("input is : %s", ch);
  // printf("\n");

  print_char_arr(ch);
  printf("\n");
  // printf("convert  : ");
}
*/
void put_stringr(char arr[], int length) {
  for (int i = length - 1; i >= 0; i--)
    putchar(arr[i]);
}

int main() {
  char ch[] = {'K', 'o', 'b', 'e'};
  printf("source   : ");
  print_char_arr(ch, sizeof(ch));
  printf("\n");
  printf("reversed : ");
  put_stringr(ch, sizeof(ch));
  printf("\n");
  return 0;
}