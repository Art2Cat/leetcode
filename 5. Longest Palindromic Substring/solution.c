#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

char *longestPalindrome(char *s) {
  int begin, middle, end, length = 0;
  int prev_begin, prev_end, prev_max = 0;
  length = strlen(s);

  if (length < 3) {
    if (length == 0 || s[0] == s[1]) {
      return s;
    }
    s[1] = '\0';
    return s;
  }

  for (int i = 0; i < (length - 1); i++) {
    for (int j = length - 1; j >= 1; j--) {
      int max = j - i + 1;
      end = j;
      middle = (i + j + 1) / 2;

      if (middle < 0) {
        continue;
      }
      int isP = 1;
      for (begin = i; begin < middle; begin++) {
        if (s[begin] != s[end]) {
          isP = 0;
          break;
        }
        end--;
      }
      if (s[i] == s[j] && isP) {
        if (max > prev_max) {
          prev_max = max;
          prev_begin = i;
          prev_end = j;
        }
      }
    }
  }
  if (prev_max == length) {
    return s;
  }
  char *result = (char *)calloc(prev_max + 1, sizeof(char));
  size_t j = 0;
  for (int i = prev_begin; i <= prev_end; ++i) {
    result[j++] = s[i];
  }
  result[j] = 0;
  return result;
}

int main() {
  char str[SIZE] = "abb";
  char str1[SIZE] = "ccc";
  char str2[SIZE] = "babadada";
  char str3[SIZE] = "aaaabaaa";
  char str4[SIZE] = "aaaabaaa";

  char *result = longestPalindrome(str);
  printf("%s\n", result);
  char *result1 = longestPalindrome(str1);
  printf("%s\n", result1);
  char *result2 = longestPalindrome(str2);
  printf("%s\n", result2);
  char *result3 = longestPalindrome(str3);
  printf("%s\n", result3);
  char *result4 = longestPalindrome(str4);
  printf("%s\n", result4);
  return 0;
}
