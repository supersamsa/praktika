#include <stdio.h>

int main(void) {
    int age;
    double seconds_in_year = 3.156e7;
    
    printf("Введите ваш возраст в годах: ");
    scanf("%d", &age);
    
    double seconds = age * seconds_in_year;
    printf("Ваш возраст в секундах: %.0f\n", seconds);
    
    return 0;
}
