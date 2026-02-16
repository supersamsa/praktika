#include <stdio.h>

int main() {
    char s[100];
    int len = 0;

    while (len < 99) {
        char c = getchar();
        
        if (c == '\n' || c == EOF) {
            break;
        }
        
        s[len] = c;
        len++;
    }
    
    s[len] = '\0';
    
    int result = 0;

    for(int i = 0; i < len; i++){
        result = result * 2;  // Умножаем на 2 (сдвиг влево)
        if(s[i] == '1'){
            result += 1;
        } else if(s[i] != '0'){
            printf("Ошибка: недопустимый символ '%c'\n", s[i]);
            return 1;
        }
    }

    printf("%s (двоичное) = %d (десятичное)\n", s, result);

    return 0;
}