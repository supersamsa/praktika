#include <stdio.h>

int main() {
    char str[256];
    int length = 0;
    
    for (int i = 0; i < 255; i++) {
        scanf("%c", &str[i]);
        if (str[i] == '\n') {
            length = i;
            break;
        }
    }
    
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}
