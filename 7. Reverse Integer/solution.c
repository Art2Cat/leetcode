#include <assert.h>
#include <limits.h>
#include <stdio.h>

int reverse(int x) {
  int sign = (x > 0 ? 1 : -1);
  x = x * sign;
  long long result = 0;

  while (x > 0) {
    int tmp = x % 10;
    result = 10 * result + tmp;
    x = x / 10;
  }

  result *= sign;
  if (result > INT_MAX || result < INT_MIN) {
    return 0;
  }
  return result;
}

int main() {
  int a = 123;
  int b = -123;
  int c = 120;

  printf("%d : %d\n", a, reverse(a));
  printf("%d : %d\n", b, reverse(b));
  printf("%d : %d\n", c, reverse(c));
  assert(reverse(a) == 321);
  assert(reverse(b) == -321);
  assert(reverse(c) == 21);
}
