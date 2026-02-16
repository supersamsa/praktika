#include <stdio.h>

int main() {
  int num;
  int even_count = 0, odd_count = 0;
  int even_sum = 0, odd_sum = 0;

  while (scanf("%d", &num) == 1 && num != 0) {
    if (num % 2 == 0) {
      even_count++;
      even_sum += num;
    } else {
      odd_count++;
      odd_sum += num;
    }
  }

  printf(" %d, среднее = %.2f\n", even_count,
         even_count > 0 ? (float)even_sum / even_count : 0);
  printf(" %d, среднее = %.2f\n", odd_count,
         odd_count > 0 ? (float)odd_sum / odd_count : 0);

  return 0;
}
