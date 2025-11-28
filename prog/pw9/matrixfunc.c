#include "matrixfunc.h"

int createMatrix(int matrix[COL][ROW]) {
  int value;
  int top = 0, bottom = COL - 1;
  int left = 0, right = ROW - 1;
  char *filename = "matrix.txt";
  char buffer[256];
  FILE *file = fopen(filename, "r");

  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; i++) {
      if (fscanf(file, "%d", &value) == 1) {
        matrix[top][i] = value;
      } else {
        printf("ERORORORRR\n");
        fclose(file);
        return 1;
      }
    }
    top++;

    for (int i = top; i <= bottom; i++) {
      if (fscanf(file, "%d", &value) == 1) {
        matrix[i][right] = value;
      } else {
        printf("ERRROERO\n");
        fclose(file);
        return 1;
      }
    }
    right--;

    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        if (fscanf(file, "%d", &value) == 1) {
          matrix[bottom][i] = value;
        } else {
          printf("ERRRRROROROROR\n");
          fclose(file);
          return 1;
        }
      }
      bottom--;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        if (fscanf(file, "%d", &value) == 1) {
          matrix[i][left] = value;
        } else {
          printf("ERRRRRORRRR\n");
          fclose(file);
          return 1;
        }
      }
      left++;
    }
  }
  fclose(file);
  return 0;
}

int oddRowSum(int matrix[COL][ROW]){
    int result = 0;
    for (int j = 1; j < COL; j+=2)
    {
        for (int i = 0; i < ROW; i++)
        {
            result += matrix[i][j];
        }
        
    }

    return result;
}

void printMatrix(int matrix[COL][ROW]){
        for (int j = 0; j < COL; j++) {
        printf("[j%2d] =  %3d", j, matrix[0][j]);
    }
    printf("\n");

    for (int i = 0; i < COL; i++) {
      for (int j = 0; j < ROW; j++) {
        printf("%3d ", matrix[i][j]);
      }
      printf("\n");
    }
}
