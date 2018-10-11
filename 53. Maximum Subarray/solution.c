#include <assert.h>
#include <math.h>
#include <stdio.h>

int maxSubArray(int *nums, int numsSize) {
  int result = nums[0];
  int sum = 0;
  for (int i = 0; i < numsSize; i++) {
    sum += nums[i];
    result = (int)fmax(sum, result);
    sum = (int)fmax(sum, 0);
  }
  return result;
}

int main() {
  int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int sum = maxSubArray(arr, 9);
  assert(sum == 6);
  printf("max sum = %d\n\n", sum);
  int arr1[] = {1, 2};
  sum = maxSubArray(arr1, 2);
  assert(sum == 3);
  printf("max sum = %d\n\n", sum);
  int arr2[] = {3, 2};
  sum = maxSubArray(arr2, 2);
  assert(sum == 5);
  printf("max sum = %d\n\n", sum);
  int arr3[] = {1, 2, -1, -2, 2, 1, -2, 1};
  sum = maxSubArray(arr3, 8);
  assert(sum == 3);
  printf("max sum = %d\n\n", sum);
  int arr4[] = {1, -1, 2};
  sum = maxSubArray(arr4, 3);
  assert(sum == 2);
  printf("max sum = %d\n\n", sum);
  int arr5[] = {-1, 2};
  sum = maxSubArray(arr5, 2);
  assert(sum == 2);
  printf("max sum = %d\n\n", sum);
  int arr6[] = {11, -5, -3, -2, 62, -1, -2, 1};
  sum = maxSubArray(arr6, 8);
  assert(sum == 63);
  printf("max sum = %d\n\n", sum);
  return 0;
}
