#include <stdio.h>

int main() {
    double balance = 1000000.0;
    int years = 0;
    double interest_rate = 0.08;
    double withdrawal = 100000.0; 
    
    while (balance > 0) {
        years++;
        balance += balance * interest_rate;
        balance -= withdrawal;
    }
    
    printf("\n через %d лет\n", years);
    
    return 0;
}
