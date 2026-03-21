#include <stdio.h>

int main() {
    double daphne = 100.0;    
    double deidre = 100.0; 
    int years = 0;
    
    while (deidre <= daphne) {
        years++;
        daphne += 100.0 * 0.10;
        deidre += deidre * 0.05; 
        
        printf(" %d: Дафна = $%.2f, Дейдра = $%.2f\n", 
               years, daphne, deidre);
    }
    
    printf("\n %d \n", years);
    printf("Дафна: $%.2f\n", daphne);
    printf("Дейдра: $%.2f\n", deidre);
    
    return 0;
}
