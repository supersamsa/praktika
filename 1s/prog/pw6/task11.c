#include <stdio.h>

#define ARTICHOKE_PRICE 2.05
#define BEET_PRICE 1.15
#define CARROT_PRICE 1.09
#define DISCOUNT_MIN 100
#define DISCOUNT_RATE 0.05

int main() {
  char choice;
  float artichoke_weight = 0, beet_weight = 0, carrot_weight = 0;
  float weight, total_weight, subtotal, discount = 0, shipping, total;

  do {
    printf("\nа) Артишоки\n");
    printf("b) Свекла\n");
    printf("c) Морковь\n");
    printf("e) Завершить\n");
    printf("Выбор: ");
    scanf(" %c", &choice);

    switch (choice) {
    case 'a':
      printf("Вес артишоков: ");
      scanf("%f", &weight);
      artichoke_weight += weight;
      break;
    case 'b':
      printf("Вес свеклы: ");
      scanf("%f", &weight);
      beet_weight += weight;
      break;
    case 'c':
      printf("Вес моркови: ");
      scanf("%f", &weight);
      carrot_weight += weight;
      break;
    case 'e':
      break;
    default:
      printf("Ошибка\n");
      continue;
    }

    printf("Артишоки: %.1f фунтов\n", artichoke_weight);
    printf("Свекла: %.1f фунтов\n", beet_weight);
    printf("Морковь: %.1f фунтов\n", carrot_weight);

  } while (choice != 'e');

  float artichoke_cost = artichoke_weight * ARTICHOKE_PRICE;
  float beet_cost = beet_weight * BEET_PRICE;
  float carrot_cost = carrot_weight * CARROT_PRICE;

  subtotal = artichoke_cost + beet_cost + carrot_cost;
  total_weight = artichoke_weight + beet_weight + carrot_weight;

  if (subtotal >= DISCOUNT_MIN) {
    discount = subtotal * DISCOUNT_RATE;
  }

  if (total_weight <= 5) {
    shipping = 6.50;
  } else if (total_weight <= 20) {
    shipping = 14.00;
  } else {
    shipping = 14.00 + (total_weight - 20) * 0.50;
  }

  total = subtotal - discount + shipping;

  printf("\n--- Чек ---\n");
  printf("Артишоки: %.1f фунтов × $%.2f = $%.2f\n", artichoke_weight,
         ARTICHOKE_PRICE, artichoke_cost);
  printf("Свекла: %.1f фунтов × $%.2f = $%.2f\n", beet_weight, BEET_PRICE,
         beet_cost);
  printf("Морковь: %.1f фунтов × $%.2f = $%.2f\n", carrot_weight, CARROT_PRICE,
         carrot_cost);
  printf("Сумма: $%.2f\n", subtotal);
  printf("Скидка: $%.2f\n", discount);
  printf("Доставка: $%.2f\n", shipping);
  printf("Итого: $%.2f\n", total);

  return 0;
}
