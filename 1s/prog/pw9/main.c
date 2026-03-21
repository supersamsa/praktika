#include "matrixfunc.h"

int main() {
  char input = ' ';
  int matrix[COL][ROW];
  int matrixInitialized = 0;

  while (input != 'e') {

    scanf(" %c", &input);

    switch (input) {
    case 'a': {
      int result = createMatrix(matrix);
      if (result == 0) {
        matrixInitialized = 1;
      } else {
        printf("EROREROREO\n");
      }
      break;
    }
    case 'b':
      if (matrixInitialized) {
        printMatrix(matrix);
      } else {
        printf("EERORORROEOE\n");
      }
      break;
    case 'c':
      if (matrixInitialized) {
        minNMaxIndexes(matrix);
      } else {
        printf("EERORORRORORO\n");
      }
      break;
    case 'd': {
      if (matrixInitialized) {
        int result = oddRowSum(matrix);
        printf("%d\n", result);
      } else {
        printf("EEROROROROROR\n");
      }
      break;
    }
    case 'e':
      break;
    default:
      break;
    }
  }

  return 0;
}