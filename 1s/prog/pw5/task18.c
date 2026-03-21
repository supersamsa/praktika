#include <stdio.h>

#define DUNBAR 150

int main() {
    int friends = 5;
    int week = 0;
    
    printf("Неделя %d: %d друзей\n", week, friends);
    
    while (friends <= DUNBAR) {
        week++;
        friends -= week; 
        friends *= 2;       
        
        printf("Неделя %d: %d друзей\n", week, friends);
    }
    
    printf("\nНа неделе %d достигнет числа дамбра %d)\n", 
           week, DUNBAR);
    
    return 0;
}
