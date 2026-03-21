#include <stdio.h>

int main() {
    int numbers[8];
    
    for (int i = 0; i < 8; i++) {
        scanf("%d", &numbers[i]);
    }
    
    for (int i = 7; i >= 0; i--) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
