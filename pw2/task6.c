#include <stdio.h>

int main(void) {
    double quarts;
    double grams_per_quarts = 950.0;
    double molecule_mass = 3.0e-23; 
    
    printf("Введите объем воды в квартах: ");
    scanf("%lf", &quarts);
    
    double total_grams = quarts * grams_per_quarts;
    double molecules = total_grams / molecule_mass;
    
    printf("Количество молекул воды: %e\n", molecules);
    
    return 0;
}
