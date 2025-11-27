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
        printf("ERORORORRR\n");
        return 1;
      }
    }
    top++;

    for (int i = top; i <= bottom; i++) {
      if (scanf("%d", &value) == 1) {
        matrix[i][right] = value;
      } else {
        printf("ERRROERO\n");
        return 1;
      }
    }
    right--;

    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        if (scanf("%d", &value) == 1) {
          matrix[bottom][i] = value;
        } else {
          printf("ERRRRROROROROR\n");
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
          printf("ERRRRRORRRR\n");
          return 1;
        }
      }
      left++;
    }
  }
  return 0;
}
