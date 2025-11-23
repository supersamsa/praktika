#ifndef MYARRAY
#define MYARRAY

#include <stdlib.h>
#include <stdio.h>

void createArray(int **arr, int *len);
void printArray(int *arr, int len);
void findAboveAverageIndices(int *arr,int len);
int countAboveValue(int *arr, int len, int k);
int fillArray(int *arr, int len);
int findLastPositiveIndex(int *arr, int len);
#endif