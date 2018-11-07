#include <stdio.h>

#define SIZE 30

int maxProfit(int* prices, int pricesSize) {
  if (pricesSize == 0) return 0;
  int max = 0;
  for (int i = 0; i < pricesSize; i++) {
    for (int j = i + 1; j < pricesSize; j++) {
      int margin = prices[j] - prices[i];
      if (margin > 0 && margin > max) {
        max = margin;
      }
    }
  }

  return max;
}

int maxProfit1(int* prices, int pricesSize) {
  int profit = 0;
  int min = 0;
  if (pricesSize == 0) return 0;
  for (int i = 1; i < pricesSize; i++) {
    min = prices[i] > prices[min] ? min : i;

    if (prices[i] > prices[min]) {
      int tmp = prices[i] - prices[min];
      profit = profit > tmp ? profit : tmp;
    }
  }

  return profit;
}

int main() {
  int arr[SIZE] = {7, 1, 5, 3, 6, 4};
  printf("%d\n", maxProfit1(arr, 6));
  int arr1[SIZE] = {7, 6, 4, 3, 1};
  printf("%d\n", maxProfit1(arr1, 5));
  int arr2[3] = {2, 4, 1};
  printf("%d\n", maxProfit1(arr2, 3));
  return 0;
}
