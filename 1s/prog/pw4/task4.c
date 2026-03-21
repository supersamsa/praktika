#include <stdio.h>

int main() {
    double cm;
    
    printf("Введите высоту в сантиметрах: ");
    scanf("%lf", &cm);
    
    while (cm > 0) {
        double inches = cm / 2.54;
        int feet = inches / 12;
        double remaining_inches = inches - feet * 12;
        
        printf("%.1f см = %d футов, %.1f дюймов\n", cm, feet, remaining_inches);
        
        printf("Введите высоту в сантиметрах (<=0 для выхода из программы): ");
        scanf("%lf", &cm);
    }
    
    printf("Работа завершена.\n");
    return 0;
}
