#include <stdio.h>

int main() {
  char ch;
  int r = 0;

  while ((ch = getchar()) != '#') {
    switch (ch) {
    case '.':
      putchar('!');
      r++;
      break;
    case '!':
      putchar('!');
      putchar('!');
      r++;
      break;
    default:
      putchar(ch);
      break;
    }
  }

  printf("%d", r);

  return 0;
}
