#include <stdio.h>

void to_base_n(int num, int base) {
  int r;

  if (base < 2 || base > 10) {
    return;
  }

  r = num % base;
  if (num >= base) {
    to_base_n(num / base, base);
  }
  printf("%d", r);
}

int main() {

  printf("129 8 10 2");
  to_base_n(129, 8);
  to_base_n(10, 2);

  return 0;
}
