#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char *s, char *t) {
  int slen = strlen(s);
  int tlen = strlen(t);
  if (slen == 0 && tlen == 0) {
    return true;
  } else if (slen == 0) {
    return false;
  } else if (tlen == 0) {
    return false;
  }
  if (slen != tlen) {
    return false;
  }

  int s_cnt[256] = {0};
  int t_cnt[256] = {0};

  for (int i = 0; i < tlen; i++) {
    s_cnt[(int)s[i]] += 1;
    t_cnt[(int)t[i]] += 1;
  }

  for (int i = 0; i < 256; i++) {
    if (s_cnt[i] != t_cnt[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  char s[] = "ac";
  char t[] = "bb";
  if (isAnagram(s, t)) {
    printf("%s is %s anagram.", s, t);
  }

  return 0;
}
