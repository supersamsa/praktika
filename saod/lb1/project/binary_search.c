#include "search.h"

int binarySearch(int *arr, int low, int high, int key) {
  if (low > high) {
    return -1;
  }

  int mid = low + (high - low) / 2;

  if (arr[mid] == key) {
    return mid;
  } else if (arr[mid] < key) {
    return binarySearch(arr, mid + 1, high, key);
  } else {
    return binarySearch(arr, low, mid - 1, key);
  }
}

int binarySearchIterative(int *arr, int low, int high, int key) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}