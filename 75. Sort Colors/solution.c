#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortColors(int *nums, int numsSize) {
  int max = 2;
  int min = 0;
  int d = max - min;
  int *count_array = (int *)calloc(d + 1, sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    count_array[nums[i] - min]++;
  }

  int sum = 0;
  for (int i = 0; i < d + 1; i++) {
    sum += count_array[i];
    count_array[i] = sum;
  }

  int *copied_nums = (int *)calloc(numsSize, sizeof(int));
  memcpy(copied_nums, nums, sizeof(int) * (numsSize));
  for (int i = numsSize - 1; i >= 0; i--) {
    nums[count_array[copied_nums[i] - min] - 1] = copied_nums[i];
    count_array[copied_nums[i] - min]--;
  }
}

void print_array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  putchar('\n');
}

int main() {
  int arr[6] = {2, 0, 2, 1, 1, 0};
  sortColors(arr, 6);

  print_array(arr, 6);
}
