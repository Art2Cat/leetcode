#include <stdio.h>

#define SIZE 30

int maxProfit(int* prices, int pricesSize) {
  int profit = 0;
  if (pricesSize == 0) return 0;
  for (int i = 1; i < pricesSize; i++) {
    if (prices[i] > prices[i - 1]) {
      int tmp = prices[i] - prices[i - 1];
      profit += tmp;
    }
  }

  return profit;
}

int main() {
  int arr[SIZE] = {7, 1, 5, 3, 6, 4};
  printf("%d\n", maxProfit(arr, 6));
  int arr1[SIZE] = {7, 6, 4, 3, 1};
  printf("%d\n", maxProfit(arr1, 5));
  int arr2[3] = {2, 4, 1};
  printf("%d\n", maxProfit(arr2, 3));
  return 0;
}
