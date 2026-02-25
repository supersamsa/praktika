#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define MAX_N 5000000
#define MAX_SEARCH 1000
#define RANGE 10000000

int linearSearch(int *arr, int n, int key);
int binarySearch(int *arr, int low, int high, int key);
int exponentialSearch(int *arr, int n, int key);

void mergeSort(int *arr, int l, int r);

double wtime();
int getrand(int min, int max);
void fillRandom(int *arr, int n);
void printTable1Header();
void printTable1Row(int num, int n, double tLin, double tBin, double tExp);
void printTable2Header();
void printTable2Row(int num, int n, int k, double tLin, double tBin,
                    double tBinSort, double tSort);
void demonstrateSearch();

#endif