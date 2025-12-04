#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

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

void analyzeText(char buff[]) {
  if (buff == NULL || buff[0] == '\0') {
    printf("Пустой ввод\n");
    return;
  }

  // Создаем таблицу для всех ASCII символов
  int freq[256] = {0};
  int total = 0;

  // Подсчитываем частоту
  for (int i = 0; buff[i] != '\0'; i++) {
    freq[(unsigned char)buff[i]]++;
    total++;
  }

  // Выводим таблицу
  printf("№\tСимвол\t\tASCII\tКол-во\tПроцент\n");
  printf("===================================================\n");

  int count = 0;
  for (int i = 0; i < 256; i++) {
    if (freq[i] > 0) {
      count++;
      char display[20];

      if (i == '\n')
        strcpy(display, "\\n");
      else if (i == '\t')
        strcpy(display, "\\t");
      else if (i == '\r')
        strcpy(display, "\\r");
      else if (i == ' ')
        strcpy(display, "space");
      else if (i == '\b')
        strcpy(display, "\\b");
      else if (isprint(i))
        sprintf(display, "'%c'", i);
      else
        sprintf(display, "0x%02X", i);

      float percent = (float)freq[i] / total * 100;
      printf("%d\t%-10s\t%d\t%d\t%.2f%%\n", count, display, i, freq[i],
             percent);
    }
  }

  printf("===================================================\n");
  printf("Всего символов: %d\n", total);
  printf("Уникальных символов: %d\n", count);
}

int main() {
  char *text = readInput();
  analyzeText(text);
  free(text);
  return 0;
}