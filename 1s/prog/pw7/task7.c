#include <stdio.h>
#include <ctype.h>

int alphabet_position(char ch) {
    if (isalpha(ch)) {
        if (isupper(ch)) {
            return ch - 'A' + 1;
        } else {
            return ch - 'a' + 1;
        }
    }
    return -1;
}

int main() {
    char ch;
    
    printf("Введите символы (Ctrl+D для завершения):\n");
    
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') continue; 
        
        int pos = alphabet_position(ch);
        if (pos != -1) {
            printf("'%c' - буква, позиция в алфавите: %d\n", ch, pos);
        } else {
            printf("'%c' - не буква\n", ch);
        }
    }
    
    printf("Программа завершена.\n");
    return 0;
}
