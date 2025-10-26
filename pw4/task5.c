#include <stdio.h>

int main() {
    int count, i;
    int sum = 0;
    
    printf("Введите количество дней: ");
    scanf("%d", &count);
    
    for (i = 1; i <= count; i++) {
        sum += i;
    }
    
    printf("Сумма за %d дней составляет $%d\n", count, sum);
    
    return 0;
}
