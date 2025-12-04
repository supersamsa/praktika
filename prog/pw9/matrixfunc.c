#include "matrixfunc.h"

int createMatrix(int matrix[COL][ROW]) {
  int value;
  int top = 0, bottom = COL - 1;
  int left = 0, right = ROW - 1;

  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; i++) {
      if (scanf("%d", &value) == 1) {
        matrix[top][i] = value;
      } else {
        printf("EROEORO\n");
        return 1;
      }
    }
    top++;

    for (int i = top; i <= bottom; i++) {
      if (scanf("%d", &value) == 1) {
        matrix[i][right] = value;
      } else {
        printf("EROEORO\n");
        return 1;
      }
    }
    right--;

    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        if (scanf("%d", &value) == 1) {
          matrix[bottom][i] = value;
        } else {
          printf("EROEORO\n");
          return 1;
        }
      }
      bottom--;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        if (scanf("%d", &value) == 1) {
          matrix[i][left] = value;
        } else {
          printf("EROEORO\n");
          return 1;
        }
      }
      left++;
    }
  }
  return 0;
}

int oddRowSum(int matrix[COL][ROW]) {
  int result = 0;
  for (int j = 1; j < COL; j += 2) {
    for (int i = 0; i < ROW; i++) {
      result += matrix[i][j];
    }
  }
  return result;
}

void printMatrix(int matrix[COL][ROW]) {
  printf("     ");
  for (int j = 0; j < COL; j++) {
    printf("[%2d] ", j);
  }
  printf("\n");

  for (int i = 0; i < ROW; i++) {
    printf("[%2d] ", i);
    for (int j = 0; j < COL; j++) {
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void minNMaxIndexes(int matrix[COL][ROW]) {
  int minI = 0, minJ = 0, maxI = 0, maxJ = 0;
  int min = matrix[0][0];
  int max = matrix[0][0];

  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      if (matrix[i][j] > max) {
        max = matrix[i][j];
        maxI = i;
        maxJ = j;
      }
      if (matrix[i][j] < min) {
        min = matrix[i][j];
        minI = i;
        minJ = j;
      }
    }
  }

  printf("min %d  i = [%d] j = [%d]\n", min, minI, minJ);
  printf("max %d  i = [%d] J =[%d]\n", max, maxI, maxJ);

  int startI = (minI < maxI) ? minI : maxI;
  int endI = (minI > maxI) ? minI : maxI;
  int startJ = (minJ < maxJ) ? minJ : maxJ;
  int endJ = (minJ > maxJ) ? minJ : maxJ;

  for (int i = startI; i <= endI; i++) {
    for (int j = startJ; j <= endJ; j++) {
      if (!((i == minI && j == minJ) || (i == maxI && j == maxJ))) {
        printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
      }
    }
  }
}