#include <stdio.h>

void print_pattern(char ch, int chars_per_line, int lines) {
    for (int line = 0; line < lines; line++) {
        for (int col = 0; col < chars_per_line; col++) {
            printf("%c", ch);
        }
        printf("\n");
    }
}

int main() {
    printf("Паттерн 5x3:\n");
    print_pattern('*', 5, 3);
    
    printf("\nПаттерн 10x2:\n");
    print_pattern('#', 10, 2);
    
    return 0;
}
