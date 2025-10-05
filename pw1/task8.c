#include <stdio.h>

void two(void) {
    printf("два\n");
}

void one_three(void) {
    printf("один\n");
    two();
    printf("три\n");
}

int main(void) {
    printf("начинаем:\n");
    one_three();
    printf("порядок!\n");
    
    return 0;
}
