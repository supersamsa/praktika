#include <stdio.h>

int main(void) {
    float cups;
    
    printf("Введите объем в чашках: ");
    scanf("%f", &cups);
    
    float pints = cups / 2.0;
    float ounces = cups * 8.0;
    float tablespoons = ounces * 2.0;
    float teaspoons = tablespoons * 3.0;
    
    printf("Эквивалентные значения:\n");
    printf("%.2f пинт\n", pints);
    printf("%.2f унций\n", ounces);
    printf("%.2f столовых ложек\n", tablespoons);
    printf("%.2f чайных ложек\n", teaspoons);
    
    return 0;
}
