#include <stdio.h>

int main() {
    int second_operand, first_operand;
    
    printf("Эта программа вычисляет результаты деления по модулю.\n");
    printf("Введите целое число, которое будет служить вторым операндом: ");
    scanf("%d", &second_operand);
    
    printf("Теперь введите первый операнд: ");
    scanf("%d", &first_operand);
    
    while (first_operand > 0) {
        int result = first_operand % second_operand;
        printf("%d %% %d равно %d\n", first_operand, second_operand, result);
        
        printf("Введите следующее число для первого операнда (<= 0 для выхода из программы): ");
        scanf("%d", &first_operand);
    }
    
    printf("Готово\n");
    return 0;
}
