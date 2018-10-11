#include <assert.h>
#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target) {
  if (numsSize == 0) {
    return 0;
  }
  int i;
  for (i = 0; i < numsSize; i++) {
    if (target <= nums[i]) {
      break;
    }
  }

  return i;
}

int main() {
  int arr[] = {1, 3, 5, 6};
  int position = searchInsert(arr, 4, 5);
  assert(position == 2);
  printf("position: %d\n", position);
  position = searchInsert(arr, 4, 2);
  assert(position == 1);
  printf("position: %d\n", position);
  position = searchInsert(arr, 4, 7);
  assert(position == 4);
  printf("position: %d\n", position);
  position = searchInsert(arr, 4, 0);
  assert(position == 0);
  printf("position: %d\n", position);
  int arr1[] = {1};
  position = searchInsert(arr1, 1, 1);
  assert(position == 0);
  printf("position: %d\n", position);
  return 0;
}
