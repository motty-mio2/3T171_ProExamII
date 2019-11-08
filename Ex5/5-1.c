#include <stdio.h>

int str_chnum(char arr[], int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    char temp = (arr[i]);

    if (temp == 99) {
      count++;
    }
  }
  return count;
}

int main() {
  char ch[] = {'c', 'h', 'o', 'c', 'o', 'c', 'a', 'k', 'e'};
  int cs = str_chnum(ch, sizeof(ch));

  printf("Cs in \"%s\" is ", ch);
  printf("%d\n", cs);

  return 0;
}