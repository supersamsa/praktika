#include <stdio.h>

#define OVERTIME_RATE 1.5
#define OVERTIME_HOURS 40
#define TAX_RATE1 0.15
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25
#define TAX_LIMIT1 300.0
#define TAX_LIMIT2 450.0

void calculate_salary(float rate) {
  float hours, gross_pay, taxes, net_pay;

  printf("Часы: ");
  scanf("%f", &hours);

  if (hours <= OVERTIME_HOURS) {
    gross_pay = hours * rate;
  } else {
    gross_pay =
        OVERTIME_HOURS * rate + (hours - OVERTIME_HOURS) * rate * OVERTIME_RATE;
  }

  if (gross_pay <= TAX_LIMIT1) {
    taxes = gross_pay * TAX_RATE1;
  } else if (gross_pay <= TAX_LIMIT2) {
    taxes = TAX_LIMIT1 * TAX_RATE1 + (gross_pay - TAX_LIMIT1) * TAX_RATE2;
  } else {
    taxes = TAX_LIMIT1 * TAX_RATE1 + 150 * TAX_RATE2 +
            (gross_pay - TAX_LIMIT2) * TAX_RATE3;
  }

  net_pay = gross_pay - taxes;

  printf("Начисления: $%.2f\n", gross_pay);
  printf("Налоги: $%.2f\n", taxes);
  printf("Зарплата: $%.2f\n\n", net_pay);
}

int main() {
  int choice;

  do {
    printf("1) $9.75\t2) $9.33\n");
    printf("3) $10.00\t4) $11.20\n");
    printf("5) Выход\n");
    printf("Выбор: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      calculate_salary(9.75);
      break;
    case 2:
      calculate_salary(9.33);
      break;
    case 3:
      calculate_salary(10.00);
      break;
    case 4:
      calculate_salary(11.20);
      break;
    case 5:
      printf("Выход\n");
      break;
    default:
      printf("Ошибка\n\n");
      break;
    }
  } while (choice != 5);

  return 0;
}
