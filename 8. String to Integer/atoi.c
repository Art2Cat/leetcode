#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int myAtoi(char *str) {
  long d = atol(str);
  if (d > INT_MAX) {
    return INT_MAX;
  } else if (d < INT_MIN) {
    return INT_MIN;
  }
  return d;
}

int main(void) {
  const char *c = "55";
  int d = atol(c);
  printf("%d\n", d);
  printf("%d\n", myAtoi("-2147483648"));
  assert(myAtoi("2147483648") == INT_MAX);
  assert(myAtoi("-1") == -1);
  assert(myAtoi("+1") == 1);
  return 0;
}
