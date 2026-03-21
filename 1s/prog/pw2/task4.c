#include <stdio.h>

int main(void) {
    float number;
    printf("Введите значение с плавающей запятой: ");
    scanf("%f", &number);
    
    printf("Запись с фиксированной запятой: %f\n", number);
    printf("Экспоненциальная форма записи: %e\n", number);
    printf("Двоично-экспоненциальное представление: %a\n", number);
    
    return 0;
}
