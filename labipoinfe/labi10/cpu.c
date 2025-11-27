#include <stdio.h>
#include <ctype.h>

#define MAXN 100000
#define LEN 65536

char memory[LEN];

int main(){

    int c, num = 0, sum = 0, count = 0;

    while((c = getchar()) != EOF && (num <= MAXN)){
        if((num*10 <= MAXN)&&isdigit(c)){
            num = num * 10 + (c - '0');
        }
    }

    for(int i = 1; i <= num; i++){
        sum +=i;
        memory[i % LEN] = i % 256;
    }

    char buffer[20];
    int index = 0;
    int temp = sum;

    if (temp == 0) {
        buffer[index++] = '0';
    } else {
        while (temp > 0) {
            buffer[index++] = '0' + (temp % 10);
            temp /= 10;
        }
    }

    while (index > 0) {
        putchar(buffer[--index]);
    }
    putchar('\n');  

    return 0;
}