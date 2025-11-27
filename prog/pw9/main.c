#include "matrixfunc.h"

int main() {
  char input = ' ';
  int matrix[COL][ROW];
  while (input != 'e') {
    scanf(" %c", &input);

    switch (input) {
    case 'a': {
      printf("ewrw");
      int result = createMatrix(matrix);
      break;
    }
    default:
      break;
    }
    for (int i = 0; i < COL; i++) {
      for (int j = 0; j < ROW; j++) {
        printf("%3d ", matrix[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}

/*
 a. Функции реализации ввода: Ввод по спирали снаружи-внутрь (вводить матрицу из
 файла <) b. Представление массива (матрица значений) (указать индексы или
 номера) c. Определение двумерных индексов элементов между минимальным и
 максимальным значениями матрицы d. Определить сумму всех не четных столбцов
 матрицы. e. Выход
*/