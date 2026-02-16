#include <stdio.h>

int main() {
    char name[50];
    float height;
    int choice;
    
    printf("Выберите единицы измерения:\n");
    printf("1 - дюймы\n2 - сантиметры\n");
    scanf("%d", &choice);
    
    printf("Введите имя: ");
    scanf("%s", name);
    
    if (choice == 1) {
        printf("Введите рост в дюймах: ");
        scanf("%f", &height);
        printf("%s, твой рост %.3f футов\n", name, height / 12.0);
    } else {
        printf("Введите рост в сантиметрах: ");
        scanf("%f", &height);
        printf("%s, твой рост %.2f метров\n", name, height / 100.0);
    }
    
    return 0;
}
