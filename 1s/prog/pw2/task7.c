#include <stdio.h>

int main(void) {
    int choice;
    float inches, cm;
    
    printf("Выберите вариант:\n");
    printf("1 - Дюймы в сантиметры\n");
    printf("2 - Сантиметры в дюймы\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Введите рост в дюймах: ");
        scanf("%f", &inches);
        cm = inches * 2.54;
        printf("%.2f дюймов = %.2f сантиметров\n", inches, cm);
    } else {
        printf("Введите рост в сантиметрах: ");
        scanf("%f", &cm);
        inches = cm / 2.54;
        printf("%.2f сантиметров = %.2f дюймов\n", cm, inches);
    }
    
    return 0;
}
