#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int isPalindrome(char* s, int i, int j) {
  while (i < j) {
    if (s[i] != s[j]) {
      return 0;
    }
    i++;
    j--;
  }
  return 1;
}

bool validPalindrome(char* s) {
  int len = strlen(s);
  if (len == 0) {
    return false;
  }
  if (len == 1) {
    return true;
  }

  int i = 0;
  int j = len - 1;

  while (i < j) {
    if (s[i] != s[j]) {
      return (isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j));
    } else {
      i++;
      j--;
    }
  }

  return true;
}

int main() {
  char str[4] = "abba";
  printf("%d\n", validPalindrome(str));

  return 0;
}