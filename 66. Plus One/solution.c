#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

int *plusOne(int *digits, int digitsSize, int *returnSize) {
  if (digitsSize == 0) {
    digits[0] = 1;
    *returnSize = 1;
    return digits;
  }
  int carry = 0;
  int i = digitsSize - 1;
  digits[i]++;
  while (i >= 0) {
    digits[i] = digits[i] + carry;
    carry = digits[i] / 10;
    digits[i] = digits[i] % 10;
    if (carry == 0) {
      break;
    }
    i--;
  }

  if (carry == 0) {
    *returnSize = digitsSize;
    return digits;
  } else {

    *returnSize = digitsSize + 1;
    int *result = (int *)calloc(*returnSize, sizeof(int));
    memset(result, 0, *returnSize);
    result[0] = 1;
    return result;
  }
}

void print_array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d", arr[i]);
    if (i != size - 1) {
      putchar(',');
    }
  }
  putchar('\n');
}

int main() {

  int arr[3] = {1, 2, 3};
  int arr1[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int arr2[2] = {9, 9};
  int *result = NULL;

  int *size = (int *)calloc(1, sizeof(int));
  result = plusOne(arr, 3, size);
  print_array(result, *size);
  result = plusOne(arr1, 10, size);
  print_array(result, *size);
  result = plusOne(arr2, 2, size);
  print_array(result, *size);
  return 0;
}
