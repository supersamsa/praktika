#ifndef MATRIX
#define MATRIX

#include <stdlib.h>
#include <stdio.h>

#define COL 10 
#define ROW 10

int createMatrix(int matrix[COL][ROW]);
int oddRowSum(int matrix[COL][ROW]);
void minNMaxIndexes(int matrix[COL][ROW]);
void printMatrix(int matrix[COL][ROW]);     

#endif