#include <stdio.h>

#define LITERS_PER_GALLON 3.785
#define KM_PER_MILE 1.609

int main() {
    float miles, gallons, mpg, liters_per_100km;
    
    printf("Введите количество пройденных миль: ");
    scanf("%f", &miles);
    printf("Введите количество израсходованных галлонов: ");
    scanf("%f", &gallons);
    
    mpg = miles / gallons;
    printf("Расход: %.1f миль на галлон\n", mpg);
    
    liters_per_100km = (100 * gallons * LITERS_PER_GALLON) / (miles * KM_PER_MILE);
    printf("Расход: %.1f литров на 100 км\n", liters_per_100km);
    
    return 0;
}
