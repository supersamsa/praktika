#include <stdio.h>

double power(double num, int pow) {
  if (pow == 0) {
    if (num == 0) {
      printf("undefine");
    }
    return 1;
  }

  if (pow == 0)
    return 1;

  if (pow < 0)
    return 1 / power(num, -pow);

  return num * power(num, pow - 1);
}

int main() {
  printf("5 2 %lf", power(5, 2));
  printf(" 10 3 %lf 3 -1 %lf 4 0 %lf 4 -4 %lf", power(10, 3), power(3, -1),
         power(4, 0), power(4, -4));
  return 0;
}
