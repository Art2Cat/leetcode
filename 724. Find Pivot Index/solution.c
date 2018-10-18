#include <stdio.h>

int pivotIndex(int* nums, int numsSize) {
  int left = 0;
  int sums = 0;
  for (int i = 0; i < numsSize; i++) {
    sums += nums[i];
  }
  for (int i = 0; i < numsSize; i++) {
    sums -= nums[i];
    if (left == (sums)) {
      return i;
    }
    left += nums[i];
  }
  return -1;
}

int main() {
  int nums[6] = {1, 7, 3, 6, 5, 6};
  printf("the pivot index is : %d\n", pivotIndex(nums, 6));
  int nums1[3] = {1, 2, 3};
  printf("the pivot index is : %d\n", pivotIndex(nums1, 3));
  int nums2[6] = {-1, -1, -1, 0, 1, 1};
  printf("the pivot index is : %d\n", pivotIndex(nums2, 6));
  int nums3[6] = {-1, -1, 0, 1, 1, 0};
  printf("the pivot index is : %d\n", pivotIndex(nums3, 6));
  return 0;
}