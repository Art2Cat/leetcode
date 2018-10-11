#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target) {
  int *result = (int *)malloc(sizeof(int) * 2);
  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (target - nums[i] == nums[j]) {
        result[0] = i;
        result[1] = j;
        return result;
      }
    }
  }
  return result;
}

int *twoSum1(int *nums, int numsSize, int target) {
  int *result = (int *)malloc(sizeof(int) * 2);
  if (numsSize < 2) {
    return result;
  }
  int i = 0;
  int j = numsSize - 1;

  while (nums[i] + nums[j] != target) {
    i++;
    j--;
  }
  result[0] = i;
  result[1] = j;
  return result;
}

int main(void) {
  int nums[4] = {2, 2, 3, 15};
  int target = 4;
  int *result = twoSum(nums, 4, target);
  for (int i = 0; i < 2; ++i) {
    printf("%d\n", result[i]);
  }

  return 0;
}
