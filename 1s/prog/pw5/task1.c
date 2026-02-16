#include <stdio.h>

int main() {
    char alphabet[26];
    
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'a' + i;
    }
    
    printf("Содержимое массива:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c ", alphabet[i]);
    }
    printf("\n");
    
    return 0;
}
