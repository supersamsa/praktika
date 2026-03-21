#include "search.h"

int exponentialSearch(int *arr, int n, int key) {
  if (arr[0] == key) {
    return 0;
  }

  int i = 1;
  while (i < n && arr[i] <= key) {
    i *= 2;
  }

  int left = i / 2;
  int right = (i < n) ? i : n - 1;

  return binarySearch(arr, left, right, key);
}