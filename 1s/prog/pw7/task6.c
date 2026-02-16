#include <stdio.h>

void sort_three(double *a, double *b, double *c) {
    double temp;
    
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
}

int main() {
    double x, y, z;
    
    printf("Введите три числа: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    
    printf("До сортировки: %.2f, %.2f, %.2f\n", x, y, z);
    sort_three(&x, &y, &z);
    printf("После сортировки: %.2f, %.2f, %.2f\n", x, y, z);
    
    return 0;
}
