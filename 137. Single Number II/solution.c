#include <stdio.h>

void shell_sort(int arr[], int n) {
  int h = 0;
  // Generate initial increments.
  while (h <= n) {
    h = 3 * h + 1;
  }
  while (h >= 1) {
    for (int i = h; i < n; i++) {
      int j = i - h;
      int get = arr[i];
      while (j >= 0 && arr[j] > get) {
        arr[j + h] = arr[j];
        j = j - h;
      }
      arr[j + h] = get;
    }
    // Increment decrement
    h = (h - 1) / 3;
  }
}

int singleNumber(int *nums, int numsSize) {
  if (numsSize == 0 || numsSize == 1) {
    return *nums;
  }
  shell_sort(nums, numsSize);
  if (nums[1] != nums[0]) return nums[0];
  if (nums[numsSize - 1] != nums[numsSize - 2]) return nums[numsSize - 1];
  int pos = nums[1];
  int i;
  for (i = 2; i < numsSize - 2; i++) {
    if (nums[i] != pos) {
      if (nums[i] != nums[i + 1]) {
        break;
      } else {
        pos = nums[i];
      }
    }
  }

  return nums[i];
}

int main() {
  int arr[4] = {2, 2, 3, 2};
  int arr1[7] = {0, 1, 0, 1, 0, 1, 99};
  int arr2[7] = {-1, -2, -1, -2, -1, -2, -9};
  int result = singleNumber(arr, 4);
  printf("single number: %d\n", result);
  result = singleNumber(arr1, 7);
  printf("single number: %d\n", result);
  result = singleNumber(arr2, 7);
  printf("single number: %d\n", result);
  return 0;
}
