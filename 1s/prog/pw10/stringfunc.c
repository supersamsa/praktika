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
    if (isprint(c)) {
      printf("%4c", c);
    } else {
      printf(" 0x%02X", ( char)c);
    }
    break;
  }
}
/* 1. Посчитать сколько и каких символов есть в тексте. Вывести
таблицу оформленную \t и \n удобную для зрительного восприятия.
*/
void countChars(char buff[]) {
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
  printf("Unique symbols: %d\n", unique);

  free(symbols);
  free(counts);
}
/*
 2. подсчитывает количество букв в каждом втором слове.
*/
#include <ctype.h>
#include <stdio.h>

void countSecWordsChars(char buff[]) {
  int wordCount = 0;
  int charCount = 0;
  int i = 0;
  int lineCounter = 0;

  while (buff[i] != '\0') {
    while (buff[i] != '\0' && !isalnum(buff[i]) && buff[i] != '_') {
      i++;
    }

    if (buff[i] == '\0')
      break;

    wordCount++;

    charCount = 0;
    while (buff[i] != '\0' && (isalnum(buff[i]) || buff[i] == '_')) {
      charCount++;
      i++;
    }

    if (wordCount % 2 == 0) {
      printf("len: %-3d", charCount);
      lineCounter++;

      if (lineCounter % 5 == 0) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  }

  if (lineCounter % 5 != 0) {
    printf("\n");
  }
}
/*
 3. Подсчитывает, сколько слов имеют указанную пользователем длину.
*/
int countInputWordLen(char buff[], int length) {
  int result = 0;
  int charCount = 0;
  int curentLen = 0;
  int i = 0;
  while (buff[i] != '\0') {
    if (buff[i] == '\0')
      break;
    while (buff[i] != '\0') {
      while (buff[i] != '\0' && !isalnum(buff[i]) && buff[i] != '_') {
        i++;
      }

      if (buff[i] == '\0')
        break;

      charCount = 0;
      while (buff[i] != '\0' && (isalnum(buff[i]) || buff[i] == '_')) {
        charCount++;
        i++;
      }

      if (charCount == length) {
        result++;
      }
    }
  }

  return result;
}
void printLarger(char *word, int length) {
  if (length == 0)
    return;

  int mid = length / 2;

  if (mid >= length - mid) {
    for (int i = 0; i < mid; i++) {
      putchar(word[i]);
    }
  } else {
    for (int i = mid; i < length; i++) {
      putchar(word[i]);
    }
  }
}

/*
 4. Разработать функцию которая Делит слово на два и оставляет большую часть.
Пример: жук -> к, солнце -> сол и обработать ей каждое слово в тексте:
*/
void output(char buff[]) {
  int i = 0;

  while (buff[i] != '\0') {
    while (buff[i] != '\0' && !isalnum(buff[i]) && buff[i] != '_') {
      putchar(buff[i]);
      i++;
    }

    if (buff[i] == '\0')
      break;

    int wordStart = i;
    int charCount = 0;

    while (buff[i] != '\0' && (isalnum(buff[i]) || buff[i] == '_')) {
      charCount++;
      i++;
    }

    printLarger(&buff[wordStart], charCount);
  }
  printf("\n");
}