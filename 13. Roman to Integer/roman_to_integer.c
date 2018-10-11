#include <stdio.h>

int roman_to_integer(char *roman) {
  char *tmp = roman;
  int result = 0;
  for (; *tmp != '\0'; tmp++) {
    switch (*tmp) {
    case 'I':
      (*(tmp + 1) == 'I' || *(tmp + 1) == 0) ? result++ : result--;
      break;
    case 'V':
      result += 5;
      break;
    case 'X':
      (*(tmp + 1) == 'L' || *(tmp + 1) == 'C') ? (result -= 10)
                                               : (result += 10);
      break;
    case 'L':
      result += 50;
      break;
    case 'C':
      (*(tmp + 1) == 'D' || *(tmp + 1) == 'M') ? (result -= 100)
                                               : (result += 100);
      break;
    case 'D':
      result += 500;
      break;
    case 'M':
      result += 1000;
      break;
    }
  }
  return result;
}

int main() {
  char iii[4] = "III";
  int x = roman_to_integer(iii);
  printf("%d\n", x);
  return 0;
}
