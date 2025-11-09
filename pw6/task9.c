#include <stdio.h>

int main() {
  int n, i, j;
  int is_prime;

  scanf("%d", &n);

  if (n <= 0) {
    printf("Число должно быть больше");
    return 1;
  }

  for (i = 2; i <= n; i++) {
    is_prime = 1;

    for (j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }

    if (is_prime) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}
