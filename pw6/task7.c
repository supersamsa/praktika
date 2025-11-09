#include <stdio.h>

#define BASE_RATE 10.0
#define OVERTIME_RATE 1.5
#define OVERTIME_HOURS 40
#define TAX_RATE1 0.15
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25
#define TAX_LIMIT1 300.0
#define TAX_LIMIT2 450.0

int main() {
  float hours, gross_pay, taxes, net_pay;

  printf("Часы: ");
  scanf("%f", &hours);

  if (hours <= OVERTIME_HOURS) {
    gross_pay = hours * BASE_RATE;
  } else {
    gross_pay = OVERTIME_HOURS * BASE_RATE +
                (hours - OVERTIME_HOURS) * BASE_RATE * OVERTIME_RATE;
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
  printf("Зарплата: $%.2f\n", net_pay);

  return 0;
}
