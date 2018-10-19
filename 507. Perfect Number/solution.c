#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkPerfectNumber(int num) {

  int j = 0;
  for (int i = num / 2; i > 0; i = i / 2) {
    if (num % i == 0) {
      j += i;
    }
    if (j == num) {
      return true;
    }
    if (i != 1 && i % 2 != 0) {
      i += 1;
    }
  }
  return false;
}

int main() {
  int n = 28;
  if (checkPerfectNumber(n)) {
    printf("%d is perfect number.\n", n);
  }
  int n1 = 99999999;
  if (checkPerfectNumber(n1)) {
    printf("%d is perfect number.\n", n1);
  }
  return 0;
}
