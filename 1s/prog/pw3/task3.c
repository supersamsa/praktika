#include <stdio.h>

int main() {
    float number;
    
    printf("Введите число с плавающей запятой: ");
    scanf("%f", &number);
    
    printf("Десятичная: %.1f\n", number);
    printf("Экспоненциальная: %.1e\n", number);
    
    printf("Десятичная: %+.3f\n", number);
    printf("Экспоненциальная: %.3E\n", number);
    
    return 0;
}
