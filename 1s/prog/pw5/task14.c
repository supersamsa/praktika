#include <stdio.h>

int main() {
    double arr1[8], arr2[8];
    
    for (int i = 0; i < 8; i++) {
        printf("Элемент %d: ", i + 1);
        scanf("%lf", &arr1[i]);
    }
    
    double sum = 0;
    for (int i = 0; i < 8; i++) {
        sum += arr1[i];
        arr2[i] = sum;
    }
    
    for (int i = 0; i < 8; i++) {
        printf("%7.2f ", arr1[i]);
    }
    printf("\n");
    
    for (int i = 0; i < 8; i++) {
        printf("%7.2f ", arr2[i]);
    }
    printf("\n");
    
    for (int i = 0; i < 8; i++) {
        printf("arr2[%d] = %.2f (сумма первых %d элементов)\n", 
               i, arr2[i], i + 1);
    }
    
    return 0;
}
