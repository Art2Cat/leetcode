#include <stdio.h>

void print(int *arr, int len) {

  printf("size: %d\n", len);
  for (int i = 0; i < len; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int removeDuplicates(int *nums, int numsSize) {
  int i, result = 0;
  for (i = 0; i < numsSize - 1; i++) {
    if (nums[i] != nums[i + 1]) {
      nums[result++] = nums[i];
    }
  }
  if (numsSize) {
    nums[result++] = nums[i];
  }
  return result;
}

int main() {
  int arr[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  print(arr, removeDuplicates(arr, 10));

  printf("\n");
  int arr1[6] = {1, 1, 1, 1, 1, 1};
  print(arr1, removeDuplicates(arr1, 6));
  printf("\n");
  int arr2[5] = {0, 0, 0, 0, 4};
  print(arr2, removeDuplicates(arr2, 5));
  printf("\n");
  int arr3[6] = {0, 1, 2, 2, 3, 4};
  print(arr3, removeDuplicates(arr3, 6));
  printf("\n");
  int arr4[5] = {0, 0, 0, 0, 0};
  print(arr4, removeDuplicates(arr4, 5));
  printf("\n");
  int arr5[2] = {1, 1};
  print(arr5, removeDuplicates(arr5, 2));
  printf("\n");
  return 0;
}
