#include <stdio.h>

void larger_of(double *x, double *y) {
    if (*x > *y) {
        *y = *x;
    } else {
        *x = *y;
    }
}

int main() {
    double a, b;
    
    printf("Введите два числа: ");
    scanf("%lf %lf", &a, &b);
    
    printf("До: a = %.2f, b = %.2f\n", a, b);
    larger_of(&a, &b);
    printf("После: a = %.2f, b = %.2f\n", a, b);
    
    double x = 3.5, y = 7.2;
    printf("\nТест 2:\n");
    printf("До: x = %.2f, y = %.2f\n", x, y);
    larger_of(&x, &y);
    printf("После: x = %.2f, y = %.2f\n", x, y);
    
    return 0;
}
