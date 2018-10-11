#include <stdbool.h>
#include <stdio.h>

bool isPrime(int n) {
  // Corner case
  if (n <= 1)
    return false;

  // Check from 2 to n-1
  for (int i = 2; i < n; i++)
    if (n % i == 0)
      return false;

  return true;
}

int decToBinary(int tmp) {
  int count = 0;
  count = 0;
  while (tmp) {
    tmp = tmp & (tmp - 1);
    count++;
  }
  return count;
}

int countPrimeSetBits(int L, int R) {
  int result = 0;
  for (int i = L; i <= R; i++) {
    if (isPrime(decToBinary(i))) {
      result++;
    }
  }
  return result;
}

int main() {
  printf("%d\n", countPrimeSetBits(10, 15));
  printf("%d\n", countPrimeSetBits(842, 888));
  return 0;
}
