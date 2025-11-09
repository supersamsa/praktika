#include <stdio.h>

int main() {
  char current, previous = '\0';
  int count = 0;

  while ((current = getchar()) != '#') {
    if (previous == 'e' && current == 'i') {
      count++;
    }
    previous = current;
  }

  printf("%d", count);

  return 0;
}
