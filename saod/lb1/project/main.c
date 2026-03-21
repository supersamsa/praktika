#include "search.h"

int binarySearchIterative(int *arr, int low, int high, int key);

int main() {

  srand(time(NULL));

  demonstrateSearch();

  int sizes1[20];
  for (int i = 0; i < 20; i++) {

    sizes1[i] = 250000 * (i + 1);
  }

  int sizes2[] = {1000000, 5000000};
  int searchCounts[] = {50,  100, 150, 200, 250, 300, 350, 400, 450, 500,
                        100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

  int *arr = (int *)malloc(MAX_N * sizeof(int));
  int *sortedArr = (int *)malloc(MAX_N * sizeof(int));
  int *searchKeys = (int *)malloc(MAX_SEARCH * sizeof(int));

  if (!arr || !sortedArr || !searchKeys) {
    printf("Ошибка выделения памяти\n");
    free(arr);
    free(sortedArr);
    free(searchKeys);
    return 1;
  }

  double start, end;
  double tLin, tBin, tExp, tSort, tBinSort;
  int iterations;

  printTable1Header();

  for (int i = 0; i < 20; i++) {
    int n = sizes1[i];

    printf("Выполняется измерение для n = %d...\n", n);

    fillRandom(arr, n);

    int key = arr[rand() % n];

    if (n < 1000000) {
      iterations = 1000;
    } else if (n < 3000000) {
      iterations = 500;
    } else {
      iterations = 100;
    }

    start = wtime();
    for (int iter = 0; iter < iterations; iter++) {
      linearSearch(arr, n, key);
    }
    end = wtime();
    tLin = (end - start) / iterations * 1e6;

    memcpy(sortedArr, arr, n * sizeof(int));
    mergeSort(sortedArr, 0, n - 1);

    start = wtime();
    for (int iter = 0; iter < iterations; iter++) {
      binarySearchIterative(sortedArr, 0, n - 1, key);
    }
    end = wtime();
    tBin = (end - start) / iterations * 1e6;

    start = wtime();
    for (int iter = 0; iter < iterations; iter++) {
      exponentialSearch(sortedArr, n, key);
    }
    end = wtime();
    tExp = (end - start) / iterations * 1e6;

    printTable1Row(i + 1, n, tLin, tBin, tExp);
  }

  printTable2Header();
  int row = 1;

  for (int si = 0; si < 2; si++) {
    int n = sizes2[si];

    printf("\nВыполняется измерение для таблицы 2, n = %d...\n", n);

    fillRandom(arr, n);

    memcpy(sortedArr, arr, n * sizeof(int));
    start = wtime();
    mergeSort(sortedArr, 0, n - 1);
    end = wtime();
    tSort = end * 1e6;

    printf("  Сортировка завершена за %.3f мкс\n", tSort);

    int startIdx = (si == 0) ? 0 : 10;
    int endIdx = (si == 0) ? 10 : 20;

    for (int ki = startIdx; ki < endIdx; ki++) {
      int k = searchCounts[ki];

      printf("  Измерение для k = %d...\n", k);

      for (int j = 0; j < k; j++) {
        searchKeys[j] = arr[rand() % n];
      }

      tLin = 0;
      for (int j = 0; j < k; j++) {
        start = wtime();
        linearSearch(arr, n, searchKeys[j]);
        end = wtime();
        tLin += (end - start) * 1e6;
      }

      tBin = 0;
      for (int j = 0; j < k; j++) {
        start = wtime();
        binarySearchIterative(sortedArr, 0, n - 1, searchKeys[j]);
        end = wtime();
        tBin += (end - start) * 1e6;
      }

      tBinSort = tSort + tBin;

      printTable2Row(row++, n, k, tLin, tBin, tBinSort, tSort);
    }
  }

  free(arr);
  free(sortedArr);
  free(searchKeys);
  
  return 0;
}