#include <ctype.h>
#include <stdio.h>

int main(void) {
  int ch;
  int upper_count = 0, lower_count = 0, other_count = 0;

  while ((ch = getchar()) != EOF) {
    if (isupper(ch)) {
      upper_count++;
    } else if (islower(ch)) {
      lower_count++;
    } else {
      other_count++;
    }
  }

  printf("upper %d\n", upper_count);
  printf("lower %d\n", lower_count);
  printf("other %d\n", other_count);

  return 0;
}
