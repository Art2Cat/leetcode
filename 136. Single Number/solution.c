#include <stdio.h>

int singleNumber(int *nums, int numsSize) {
  int result = 0;
  for (int i = 0; i < numsSize; i++) {
    result ^= nums[i];
  }
  return result;
}

int main() {
  int arr[3] = {2, 2, 1};
  int arr1[5] = {-1, -2, -1, -2, -9};
  int result = singleNumber(arr, 3);
  printf("single number: %d\n", result);
  result = singleNumber(arr1, 5);
  printf("single number: %d\n", result);
  return 0;
}
