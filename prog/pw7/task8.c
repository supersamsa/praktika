#include <stdio.h>

double power(double num, int pow) {
  double result = num;
  if (pow == 0) {
    if (num == 0) {
      printf("undefine");
    }
    return 1;
  } else if (pow > 0) {
    for (int i = 1; i < pow; i++) {
      result *= num;
    }
  } else {
    for (int i = 1; i < pow; i++) {
      result *= num;
    }
    result = 1 / result;
  }

  return result;
}

int main() {
  printf("5 2 %lf", power(5, 2));
  printf(" 10 3 %lf 3 -1 %lf 4 0 %lf 4 -4 %lf", power(10, 3), power(3, -1),
         power(4, 0), power(4, -4));
  return 0;
}
