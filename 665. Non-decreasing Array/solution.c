#include <stdbool.h>
#include <stdio.h>

bool checkPossibility(int* nums, int numsSize) {
  int prev = nums[0];
  int adjusted = 0;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] >= prev) {
      prev = nums[i];
      continue;
    }
    if (adjusted) {
      return 0;
    }
    adjusted = 1;
    if (i < 2 || nums[i - 2] <= nums[i]) {
      prev = nums[i];
    }
  }
  return 1;
}

int main() {
  int arr[3] = {4, 2, 3};
  int arr1[3] = {4, 2, 1};
  int arr2[4] = {-1, 4, 2, 3};

  printf("is Non-decreasing Array : %d\n", checkPossibility(arr, 3));
  printf("is Non-decreasing Array : %d\n", checkPossibility(arr1, 3));
  printf("is Non-decreasing Array : %d\n", checkPossibility(arr2, 4));
  return 0;
}