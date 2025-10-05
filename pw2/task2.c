#include <stdio.h>

int main(void) {
    int code;
    printf("Введите код ASCII: ");
    scanf("%d", &code);
    printf("Символ с кодом %d: %c\n", code, code);
    
    return 0;
}
