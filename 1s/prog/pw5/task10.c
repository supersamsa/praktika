#include <stdio.h>

int main() {
    int lower, upper;
    
    while (scanf("%d %d", &lower, &upper) == 2 && lower < upper) {
        int sum = 0;
        
        for (int i = lower; i <= upper; i++) {
            sum += i * i;
        }
        
        printf(" %d  %d  %d\n",
               lower * lower, upper * upper, sum);
    }
    
    return 0;
}
