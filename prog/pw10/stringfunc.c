#include "stringfunc.h"

char *readInput() {
  int capacity = 1024;
  int size = 0;
  char *buffer = malloc(capacity);

  int c;
  while ((c = getchar()) != EOF) {
    if (size + 1 >= capacity) {
      capacity *= 2;
      buffer = realloc(buffer, capacity);
    }
    buffer[size++] = (char)c;
  }
  buffer[size] = '\0';

  return buffer;
}

void printChar(char c) {
  switch (c) {
  case '\n':
    printf("  \\n");
    break;
  case '\t':
    printf("  \\t");
    break;
  case '\r':
    printf("  \\r");
    break;
  case '\0':
    printf("  \\0");
    break;
  case '\\':
    printf("  \\\\");
    break;
  case ' ':
    printf("  ' '");
    break;
  default:
    if (isprint((unsigned char)c)) {
      printf("%4c", c);
    } else {
      printf(" 0x%02X", (unsigned char)c);
    }
    break;
  }
}

void printChars(char buff[]) {
  int capacity = 256;
  char *symbols = malloc(capacity * sizeof(char));
  int *counts = malloc(capacity * sizeof(int));
  int unique = 0;

  for (int i = 0; i < capacity; i++) {
    symbols[i] = '\0';
    counts[i] = 0;
  }

  for (int i = 0; buff[i] != '\0'; i++) {
    char current = buff[i];
    int found = 0;

    for (int j = 0; j < unique; j++) {
      if (symbols[j] == current) {
        counts[j]++;
        found = 1;
        break;
      }
    }

    if (!found) {
      if (unique >= capacity) {
        capacity *= 2;
        symbols = realloc(symbols, capacity * sizeof(char));
        counts = realloc(counts, capacity * sizeof(int));
      }

      symbols[unique] = current;
      counts[unique] = 1;
      unique++;
    }
  }

  printf("____________________\n");
  printf("  CHAR    COUNT     \n");
  printf("____________________\n");

  for (int i = 0; i < unique; i++) {
    printChar(symbols[i]);
    printf(" %8d \n", counts[i]);

    if ((i + 1) % 10 == 0 && (i + 1) != unique) {
      printf("____________________\n");
    }
  }

  printf("____________________\n");
  printf("Всего уникальных символов: %d\n", unique);

  free(symbols);
  free(counts);
}

int countChars();
int countSecWordsChars();
int contInputWordLen();
void output();