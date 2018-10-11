#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 125

int longestPalindrome(char *s) {
  int table[MAXSIZE] = {0};

  int len = strlen(s);
  int i = 0;
  int ct = 0;
  while (i < len) {
    ++table[(int)s[i]];
    if (table[(int)s[i++]] % 2 == 0) {
      ct += 2;
    }
  }
  if (ct == len) {
    return ct;
  }
  return ct + 1;
}

int main(void) {

  assert(longestPalindrome("abccccd") == 5);
  printf("%d\n", longestPalindrome("abccccdd"));
  assert(longestPalindrome("dhggsgghzd") == 9);
  printf("%d\n", longestPalindrome("hhdhggsgghzd"));
  assert(longestPalindrome("abcfzdzfcd") == 9);
  printf("%d\n", longestPalindrome("abcfzdzfcd"));
  return 0;
}
