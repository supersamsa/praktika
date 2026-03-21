#include <stdio.h>

int main() {
    double num1, num2;
    
    while (scanf("%lf %lf", &num1, &num2) == 2) {
        double result = (num1 - num2) / (num1 * num2);
        printf("(%.2f - %.2f) / (%.2f * %.2f) = %.2f\n", 
               num1, num2, num1, num2, result);
    }
    
    return 0;
}
