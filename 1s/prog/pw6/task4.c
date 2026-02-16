#include <stdio.h>

int main() {
  char ch;
  int replacements = 0;

  while ((ch = getchar()) != '#') {
    if (ch == '.') {
      putchar('!');
      replacements++;
    } else if (ch == '!') {
      putchar('!');
      putchar('!');
      replacements++;
    } else {
      putchar(ch);
    }
  }

  printf("%d\n", replacements);

  return 0;
}
