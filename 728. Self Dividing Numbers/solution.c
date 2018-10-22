#include <stdio.h>
#include <stdlib.h>

int* selfDividingNumbers(int left, int right, int* returnSize) {
  int count = 0;
  int* result = (int*)calloc(right - left + 1, sizeof(int));
  for (int i = left; i <= right; i++) {
    int tmp = i;
    int flag = 1;
    while (tmp) {
      int diviser = tmp % 10;
      tmp /= 10;
      if (diviser == 0 || i % diviser != 0) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      result[count] = i;
      count++;
    }
  }
  *returnSize = count;
  return result;
}

int main() {
  int* size = (int*)malloc(sizeof(int));
  int* result = selfDividingNumbers(1, 22, size);
  printf("size: %d\n", *size);
  return 0;
}