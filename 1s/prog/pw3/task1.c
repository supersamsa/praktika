#include <stdio.h>
#include <string.h>

int main() {
    char name[50], surname[50];
    
    printf("Введите имя: ");
    scanf("%s", name);
    printf("Введите фамилию: ");
    scanf("%s", surname);
    
    printf("%s.%s., ^%s\n", surname, name, name);
    
    return 0;
}
