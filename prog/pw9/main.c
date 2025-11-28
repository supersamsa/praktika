#include "matrixfunc.h"

int main() {
  char input = ' ';
  int matrix[COL][ROW];
  while (input != 'e') {
    scanf(" %c", &input);

    switch (input) {
    case 'a': {
      int result = createMatrix(matrix);
      break;
    }
    case 'b':
    printMatrix(matrix);
    break;
    case 'c':
    break;
    case 'd':{
        int result = oddRowSum(matrix);
            printf("%d", result);
        break;
    }
    default:
      break;
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