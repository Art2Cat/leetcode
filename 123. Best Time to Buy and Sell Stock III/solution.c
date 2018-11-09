#include <assert.h>
#include <stdio.h>

#define SIZE 30

int maxProfit(int* prices, int pricesSize) {
	int profit = 0;
	// if (pricesSize == 0) return 0;
	// for (int i = 1; i < pricesSize; i++) {
	//   if (prices[i] > prices[i - 1]) {
	//     int tmp = prices[i] - prices[i - 1];
	//     profit += tmp;
	//   }
	// }

	return profit;
}

int main() {
	int arr[SIZE] = {3, 3, 5, 0, 0, 3, 1, 4};

	printf("%d\n", maxProfit(arr, 6));
	assert(6 == maxProfit(arr, 8));
	int arr1[SIZE] = {1, 2, 3, 4, 5};
	printf("%d\n", maxProfit(arr1, 5));
	assert(4 == maxProfit(arr1, 4));
	int arr2[SIZE] = {7, 6, 4, 3, 1};
	printf("%d\n", maxProfit(arr2, 5));
	assert(0 == maxProfit(arr2, 5));
	return 0;
}
