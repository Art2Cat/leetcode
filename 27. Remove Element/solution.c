#include <stdio.h>

void print(int *arr, int len) {

  printf("size: %d\n", len);
  for (int i = 0; i < len; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int removeElement(int *nums, int numsSize, int val) {
  int i, result = 0;
  for (i = 0; i < numsSize; i++) {
    if (nums[i] != val) {
      nums[result++] = nums[i];
    }
  }
  return result;
}

int main() {
  int arr[] = {3, 2, 2, 3};
  print(arr, removeElement(arr, 4, 3));
  int arr1[] = {0, 1, 2, 2, 3, 0, 4, 2};
  print(arr1, removeElement(arr1, 8, 2));
  int arr2[] = {2};
  print(arr2, removeElement(arr2, 1, 3));

  return 0;
}
