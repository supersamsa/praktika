#include <stdio.h>
#include <string.h>

int main() {
    char name[50], surname[50];
    int len_name, len_surname;
    
    printf("Введите имя: ");
    scanf("%s", name);
    printf("Введите фамилию: ");
    scanf("%s", surname);
    
    len_name = strlen(name);
    len_surname = strlen(surname);
    
    printf("%s %s\n", name, surname);
    printf("%*d %*d\n", len_name, len_name, len_surname, len_surname);
    
    printf("\n%s %s\n", name, surname);
    printf("%-*d %-*d\n", len_name, len_name, len_surname, len_surname);
    
    return 0;
}
