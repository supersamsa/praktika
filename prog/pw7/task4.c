#include <stdio.h>

double harmonic_mean(double a, double b) {
    double inverse_a = 1.0 / a;
    double inverse_b = 1.0 / b;
    double mean_inverse = (inverse_a + inverse_b) / 2.0;
    return 1.0 / mean_inverse;
}

int main() {
    double num1, num2;
    
    printf("Введите два числа: ");
    scanf("%lf %lf", &num1, &num2);
    
    double result = harmonic_mean(num1, num2);
    printf("Среднее гармоническое чисел %.2f и %.2f = %.2f\n", num1, num2, result);
    
    printf("Тестовые примеры:\n");
    printf("harmonic_mean(2, 2) = %.2f\n", harmonic_mean(2, 2));
    printf("harmonic_mean(1, 2) = %.2f\n", harmonic_mean(1, 2));
    printf("harmonic_mean(3, 7) = %.2f\n", harmonic_mean(3, 7));
    
    return 0;
}
