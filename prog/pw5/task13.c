#include <stdio.h>

int main() {
    int powers[8];
    
    for (int i = 0; i < 8; i++) {
        powers[i] = 1;
        for (int j = 0; j <= i; j++) {
            powers[i] *= 2;
        }
    }
    
    int index = 0;
    do {
        printf("%d ", powers[index]);
        index++;
    } while (index < 8);
    printf("\n");
    
    return 0;
}
