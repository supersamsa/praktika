#include <stdio.h>

int main() {
  int category;
  float income, tax;

  do {
    printf("\nКатегория:\n");
    printf("1) Одиночка\n");
    printf("2) Глава семьи\n");
    printf("3) Брак совместно\n");
    printf("4) Брак раздельно\n");
    printf("5) Выход\n");
    printf("Выбор: ");
    scanf("%d", &category);

    if (category == 5)
      break;

    printf("Доход: ");
    scanf("%f", &income);

    switch (category) {
    case 1:
      if (income <= 17850)
        tax = income * 0.15;
      else
        tax = 17850 * 0.15 + (income - 17850) * 0.28;
      break;
    case 2:
      if (income <= 23900)
        tax = income * 0.15;
      else
        tax = 23900 * 0.15 + (income - 23900) * 0.28;
      break;
    case 3:
      if (income <= 29750)
        tax = income * 0.15;
      else
        tax = 29750 * 0.15 + (income - 29750) * 0.28;
      break;
    case 4:
      if (income <= 14875)
        tax = income * 0.15;
      else
        tax = 14875 * 0.15 + (income - 14875) * 0.28;
      break;
    default:
      printf("Ошибка\n");
      continue;
    }

    printf("Налог: $%.2f\n", tax);

  } while (1);

  return 0;
}
