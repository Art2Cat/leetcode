#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
  if (x < 0 || (x % 10 == 0 && x != 0)) {
    return false;
  }
  int reverted = 0;
  while (x > reverted) {
    reverted = reverted * 10 + (x % 10);
    x /= 10;
  }
  return x == reverted / 10 || reverted == x;
}

int main(void) {
  int origin = -2147447412;

  printf("%d\n", origin);

  if (isPalindrome(origin)) {
    printf("%d is palindrome number.", origin);
  } else {
    printf("%d is not palindrome number.", origin);
  }

  return 0;
}
