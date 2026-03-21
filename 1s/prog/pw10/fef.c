#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void countSecWordsChars(char buff[]) {
  int wordCount = 0;
  int charCount = 0;
  int inWord = 0; // Флаг: находимся ли внутри слова

  for (int i = 0; buff[i] != '\0'; i++) {
    if (isalnum(buff[i]) || buff[i] == '_') { // Символ принадлежит слову
      if (!inWord) {
        inWord = 1;
        wordCount++;

        if (wordCount % 2 == 0) { // Чётное слово (каждое второе)
          charCount = 1;          // Начинаем подсчёт
        }
      } else if (inWord && wordCount % 2 == 0) {
        charCount++; // Увеличиваем счётчик для второго слова
      }
    } else { // Разделитель
      if (inWord && wordCount % 2 == 0) {
        printf("Word %d: %d characters\n", wordCount, charCount);
      }
      inWord = 0;
    }
  }

  // Обработка последнего слова, если строка заканчивается словом
  if (inWord && wordCount % 2 == 0) {
    printf("Word %d: %d characters\n", wordCount, charCount);
  }
}

int main() {
  char text[] = "Hello?.!! world, this is a test string!";
  countSecWordsChars(text);
  return 0;
}