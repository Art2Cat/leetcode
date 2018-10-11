#include <assert.h>
#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
  int sourceLen = strlen(haystack);
  int targetLen = strlen(needle);

  if (targetLen == 0) {
    return 0;
  }
  char first = needle[0];
  int max = 0 + (sourceLen - targetLen);

  for (int i = 0; i <= max; i++) {
    if (haystack[i] != first) {
      while (++i <= max && haystack[i] != first)
        ;
    }
    if (i <= max) {
      int j = i + 1;
      int end = j + targetLen - 1;
      for (int k = 1; j < end && haystack[j] == needle[k]; j++, k++)
        ;
      if (j == end) {
        return i;
      }
    }
  }
  return -1;
}

int main() {
  char haystack[] = "hello";
  char needle[] = "ll";
  printf("%d\n", strStr(haystack, needle));
  assert(strStr(haystack, needle) == 2);
  return 0;
}
