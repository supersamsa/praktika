#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 100000
#define DEFAULT_L1_SIZE 256

char memory[65536];
char* data = NULL;
char cpu[100] = "Ryzen 5 6600H";

int scanNum(){
    int num = 0;
    char c;
    
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            if (num <= (MAXN - (c - '0')) / 10) {
                num = num * 10 + (c - '0');
            } else {
                num = MAXN;
                break;
            }
        } else {
            break;
        }
    }
    return num;
}

void printSum(long long sum){
    char buffer[20];
    int index = 0;
    long long temp = sum;
    
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
}

void getInfo(int *l1){
    char line[256];
    
    *l1 = DEFAULT_L1_SIZE;

    if (fgets(line, sizeof(line), stdin) != NULL) {
        int num = 0;
        for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                if (num * 10 + (line[i] - '0') <= 1024) {
                    num = num * 10 + (line[i] - '0');
                }
            }
        }
        if (num > 0) {
            *l1 = num;
        }
    }

    if (fgets(line, sizeof(line), stdin) != NULL) {
        int i = 0;
        for (i = 0; line[i] != '\0' && line[i] != '\n' && i < sizeof(cpu) - 1; i++) {
            cpu[i] = line[i];
        }
        cpu[i] = '\0';
    }
}

void codedPrint(long long sum){
    char buffer[20];
    int index = 0;
    long long temp = sum;
    
    if (temp == 0) {
        buffer[index++] = '0';
    } else {
        while (temp > 0) {
            buffer[index++] = '0' + (temp % 10);
            temp /= 10;
        }
    }

    int i = 0;
    int cpu_len = strlen(cpu);
    
    while (index > 0) {
        if (i >= cpu_len) {
            i = 0;
        }

        putchar((((buffer[--index] - '0') + cpu[i]) % 10) + '0');
        i++;
    }
    putchar('\n');
}

int main() {
    int num = 0, l1;
    long long sum = 0;
    
    setbuf(stdin, NULL);

    getInfo(&l1);

    int data_size = (l1 + 128) * 1024;
    data = (char*)malloc(data_size);
    if (data == NULL) {
        return 1;
    }

    num = scanNum();

    if (num < 0) {
        num = 0;
    } else if (num > MAXN) {
        num = MAXN;
    }
    
    for (int i = 1; i <= num; i++) {
        sum += i;
        memory[i % 65536] = i % 256;
        data[i % data_size] = (sum + i) % 256;
    }
    
   printSum(sum);
   codedPrint(sum);
 
    free(data);
    
    return 0;
}