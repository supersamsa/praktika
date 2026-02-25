#include "search.h"

double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max) {
  return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void fillRandom(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = getrand(0, RANGE + 1);
  }
}

void printTable1Header() {
  printf("\n%s\n", "==================================================");
  printf("Таблица 1. Время выполнения поиска элемента в массиве\n");
  printf("%-4s %-20s %-25s %-25s %-25s\n", "#", "Кол-во элементов",
         "Линейный поиск, мкс", "Бинарный поиск, мкс", "Экспоненц. поиск, мкс");
  printf("%s\n", "--------------------------------------------------");
}

void printTable1Row(int num, int n, double tLin, double tBin, double tExp) {
  printf("%-4d %-20d %-25.3f %-25.3f %-25.3f\n", num, n, tLin, tBin, tExp);
}

void printTable2Header() {
  printf("\n%s\n", "==================================================");
  printf("Таблица 2. Результаты экспериментов\n");
  printf("%-4s %-20s %-20s %-15s %-15s %-20s %-15s\n", "#", "Кол-во в массиве",
         "Кол-во для поиска", "Линейный, мкс", "Бинарный, мкс",
         "Бинарный+сорт, мкс", "Сортировка, мкс");
  printf("%s\n", "--------------------------------------------------");
}

void printTable2Row(int num, int n, int k, double tLin, double tBin,
                    double tBinSort, double tSort) {
  printf("%-4d %-20d %-20d %-15.3f %-15.3f %-20.3f %-15.3f\n", num, n, k, tLin,
         tBin, tBinSort, tSort);
}

void demonstrateSearch() {
  printf("\n%s\n", "==================================================");
  printf("ДЕМОНСТРАЦИЯ РАБОТЫ АЛГОРИТМОВ ПОИСКА\n");

  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int n = 10;
  int key = 13;

  printf("Массив: [");
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if (i < n - 1)
      printf(", ");
  }
  printf("]\n");
  printf("Ищем элемент: %d\n\n", key);

  int linRes = linearSearch(arr, n, key);
  printf("Линейный поиск: элемент %s, индекс = %d\n",
         linRes != -1 ? "найден" : "не найден", linRes);

  int binRes = binarySearch(arr, 0, n - 1, key);
  printf("Бинарный поиск: элемент %s, индекс = %d\n",
         binRes != -1 ? "найден" : "не найден", binRes);

  int expRes = exponentialSearch(arr, n, key);
  printf("Экспоненциальный поиск: элемент %s, индекс = %d\n",
         expRes != -1 ? "найден" : "не найден", expRes);

  key = 8;
  printf("\nИщем отсутствующий элемент: %d\n", key);
  linRes = linearSearch(arr, n, key);
  printf("Линейный поиск: %s\n", linRes != -1 ? "найден" : "не найден");
  binRes = binarySearch(arr, 0, n - 1, key);
  printf("Бинарный поиск: %s\n", binRes != -1 ? "найден" : "не найден");
  expRes = exponentialSearch(arr, n, key);
  printf("Экспоненциальный поиск: %s\n", expRes != -1 ? "найден" : "не найден");
}