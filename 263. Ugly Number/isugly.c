#include <stdbool.h>
#include <stdio.h>

bool isUgly(int num) {
  if (num == 0) {
    return false;
  }
  if (num == 1) {
    return true;
  }

  int pfactor[] = {2, 3, 5};
  for (int i = 0; i < 3; i++) {
    while (num % pfactor[i] == 0) {
      num /= pfactor[i];
    }
  }

  return num == 1;
}

int main(void) {
  printf("%d\n", isUgly(6));
  return 0;
}
