#include <stdio.h>

int main() {
    int n;
    
    while (scanf("%d", &n) == 1 && n > 0) {
        double sum1 = 0.0, sum2 = 0.0;
        
        for (int i = 1; i <= n; i++) {
            sum1 += 1.0 / i;
            
            if (i % 2 == 0) {
                sum2 -= 1.0 / i;
            } else {
                sum2 += 1.0 / i;
            }
        }
        
        printf("%d %.6f\n", n, sum1);
        printf("%d  %.6f\n", n, sum2);
    }
    
    return 0;
}
