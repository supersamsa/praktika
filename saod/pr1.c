#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAX_N 5000000
#define MAX_SEARCH 1000
#define RANGE 10000000

void mergeSort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);
int linearSearch(int *arr, int n, int key);
int binarySearch(int *arr, int low, int high, int key);
int exponentialSearch(int *arr, int n, int key);
long long currentTimeMicros();
void fillRandom(int *arr, int n);
void printTable1Header();
void printTable1Row(int num, int n, long long tLin, long long tBin, long long tExp);
void printTable2Header();
void printTable2Row(int num, int n, int k, long long tLin, long long tBin, long long tBinSort, long long tSort);

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    free(L);
    free(R);
}

int linearSearch(int *arr, int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

int binarySearch(int *arr, int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int exponentialSearch(int *arr, int n, int key) {
    if (arr[0] == key) return 0;
    int i = 1;
    while (i < n && arr[i] <= key) i *= 2;
    return binarySearch(arr, i/2, (i < n ? i : n-1), key);
}

long long currentTimeMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}

void fillRandom(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (RANGE + 1);
}

void printTable1Header() {
    printf("\nТаблица 1. Время выполнения поиска элемента в массиве\n");
    printf("%-4s %-20s %-25s %-25s %-25s\n", 
           "#", "Кол-во элементов", "Линейный поиск, мкс", 
           "Бинарный поиск, мкс", "Экспоненциальный поиск, мкс");
}

void printTable1Row(int num, int n, long long tLin, long long tBin, long long tExp) {
    printf("%-4d %-20d %-25lld %-25lld %-25lld\n", num, n, tLin, tBin, tExp);
}

void printTable2Header() {
    printf("\nТаблица 2. Результаты экспериментов\n");
    printf("%-4s %-20s %-20s %-15s %-15s %-20s %-15s\n", 
           "#", "Кол-во в массиве", "Кол-во для поиска", 
           "Линейный, мкс", "Бинарный, мкс", 
           "Бинарный+сорт, мкс", "Сортировка, мкс");
}

void printTable2Row(int num, int n, int k, long long tLin, long long tBin, 
                    long long tBinSort, long long tSort) {
    printf("%-4d %-20d %-20d %-15lld %-15lld %-20lld %-15lld\n", 
           num, n, k, tLin, tBin, tBinSort, tSort);
}

int main() {
    srand(time(NULL));
    
    int sizes1[20];
    for (int i = 0; i < 20; i++) {
        sizes1[i] = 250000 * (i + 1);
    }
    
    int sizes2[] = {1000000, 5000000};
    int searchCounts[] = {50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    
    int *arr = (int*)malloc(MAX_N * sizeof(int));
    int *arrCopy = (int*)malloc(MAX_N * sizeof(int));
    int *searchKeys = (int*)malloc(MAX_SEARCH * sizeof(int));
    
    if (!arr || !arrCopy || !searchKeys) {
        printf("Ошибка выделения памяти\n");
        free(arr); free(arrCopy); free(searchKeys);
        return 1;
    }
    
    long long start, end;
    long long tLin, tBin, tExp, tSort, tBinSort;
    
    printTable1Header();
    for (int i = 0; i < 20; i++) {
        int n = sizes1[i];
        
        fillRandom(arr, n);
        
        int key = arr[rand() % n];
        
        start = currentTimeMicros();
        linearSearch(arr, n, key);
        end = currentTimeMicros();
        tLin = end - start;
        
        for (int j = 0; j < n; j++) arrCopy[j] = arr[j];
        
        mergeSort(arrCopy, 0, n - 1);
        
        start = currentTimeMicros();
        binarySearch(arrCopy, 0, n - 1, key);
        end = currentTimeMicros();
        tBin = end - start;
        
        start = currentTimeMicros();
        exponentialSearch(arrCopy, n, key);
        end = currentTimeMicros();
        tExp = end - start;
        
        printTable1Row(i + 1, n, tLin, tBin, tExp);
    }
    
    printTable2Header();
    int row = 1;
    
    for (int si = 0; si < 2; si++) {
        int n = sizes2[si];
        
        fillRandom(arr, n);
        
        for (int j = 0; j < n; j++) arrCopy[j] = arr[j];
        start = currentTimeMicros();
        mergeSort(arrCopy, 0, n - 1);
        end = currentTimeMicros();
        tSort = end - start;
        
        int startIdx = (si == 0) ? 0 : 10;
        int endIdx = (si == 0) ? 10 : 20;
        
        for (int ki = startIdx; ki < endIdx; ki++) {
            int k = searchCounts[ki];
            
            for (int j = 0; j < k; j++) {
                searchKeys[j] = rand() % (RANGE + 1);
            }
            
            tLin = 0;
            for (int j = 0; j < k; j++) {
                start = currentTimeMicros();
                linearSearch(arr, n, searchKeys[j]);
                end = currentTimeMicros();
                tLin += (end - start);
            }
            
            tBin = 0;
            for (int j = 0; j < k; j++) {
                start = currentTimeMicros();
                binarySearch(arrCopy, 0, n - 1, searchKeys[j]);
                end = currentTimeMicros();
                tBin += (end - start);
            }
            
            tBinSort = tSort + tBin;
            
            printTable2Row(row++, n, k, tLin, tBin, tBinSort, tSort);
        }
    }
    
    free(arr);
    free(arrCopy);
    free(searchKeys);

    return 0;
}