#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    
    printf("Введите имя: ");
    scanf("%s", name);
    
    printf("\"%s\"\n", name);
    
    printf("\"%20s\"\n", name);
    
    printf("\"%-20s\"\n", name);
    
    int width = strlen(name) + 3;
    printf("\"%*s\"\n", width, name);
    
    return 0;
}
