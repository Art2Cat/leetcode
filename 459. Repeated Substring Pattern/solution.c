#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool repeatedSubstringPattern(char *s) {
  int n = strlen(s);
  int j = -1;
  if (n <= 1)
    return false;
  int *arr = (int *)calloc(n, sizeof(int));
  arr[0] = -1;
  for (int i = 1; i < n; i++) {
    while (j >= 0 && s[i] != s[j + 1]) {
      j = arr[j];
    }
    if (s[i] == s[j + 1]) {
      arr[i] = ++j;
    } else {
      arr[i] = -1;
    }
  }
  free(arr);
  return (++j > 0 && n % (n - j) == 0);
}

int main() {
  char str[] = "ababab";
  assert(repeatedSubstringPattern(str));
  printf("%s\n", str);
  char str1[] = "aba";
  assert(repeatedSubstringPattern(str1));
  printf("%s\n", str1);
  char str2[] = "aaaaaaaaaaaa";
  assert(repeatedSubstringPattern(str2));
  printf("%s\n", str2);
  return 0;
}
