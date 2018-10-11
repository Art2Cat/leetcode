#
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {

  int len = strlen(s);
  if (len == 0) {
    return 0;
  }

  int count = 0;
  int flag = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (flag && s[i] == ' ') {
      return len;
    }
    if (s[i] != ' ') {
      flag = 1;
    }

    if (flag) {
      count++;
    }
  }
  return count;
}
