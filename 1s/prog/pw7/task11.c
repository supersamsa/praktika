#include <stdio.h>
void Fibonacci(int num) {
  int current = num, prev = num, res = 0;

  while (getchar() != EOF) {
    res = current + prev;
    printf("%d   ", res);

    prev = current;
    current = res;
  }
}
int main() {
  Fibonacci(1);

  return 0;
}
