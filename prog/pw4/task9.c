#include <stdio.h>

void Temperatures(double fahrenheit) {
    const double CELSIUS_FACTOR = 5.0 / 9.0;
    const double FAHRENHEIT_OFFSET = 32.0;
    const double KELVIN_OFFSET = 273.16;
    
    double celsius = CELSIUS_FACTOR * (fahrenheit - FAHRENHEIT_OFFSET);
    double kelvin = celsius + KELVIN_OFFSET;
    
    printf("Температура по Фаренгейту: %.2f°F\n", fahrenheit);
    printf("Температура по Цельсию: %.2f°C\n", celsius);
    printf("Температура по Кельвину: %.2fK\n\n", kelvin);
}

int main() {
    double temp;
    int result;
    
    printf("Введите температуру по Фаренгейту (q для выхода): ");
    
    while ((result = scanf("%lf", &temp)) == 1) {
        Temperatures(temp);
        printf("Введите температуру по Фаренгейту (q для выхода): ");
    }
    
    printf("Программа завершена.\n");
    return 0;
}
