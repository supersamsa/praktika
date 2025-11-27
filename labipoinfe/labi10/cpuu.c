#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXN 100000
#define DEFAULT_L1_SIZE 256

int get_cache() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
    if (!cpuinfo) return DEFAULT_L1_SIZE;
    
    char line[256];
    int l1d_cache = 0;
    
    while (fgets(line, sizeof(line), cpuinfo)) {
        if (strstr(line, "cache size")) {
            char* cache_str = strstr(line, ":");
            if (cache_str) {
                sscanf(cache_str + 1, "%d", &l1d_cache);
            }
            break;
        }
    }
    fclose(cpuinfo);
    return l1d_cache;
}

long get_ram() {
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (!meminfo) return 0;
    
    char line[256];
    long ram_kb = 0;
    
    while (fgets(line, sizeof(line), meminfo)) {
        if (strstr(line, "MemTotal")) {
            sscanf(line, "MemTotal: %ld kB", &ram_kb);
            break;
        }
    }
    fclose(meminfo);
    return ram_kb;
}

char memory[65536];
char* data = NULL;

int main(int argc, char *argv[]) {
    int c, num = 0, sum = 0;
    
    int l1 = get_cache();
    printf("L1 Cache size: %d KB\n", l1);
    printf("Total RAM: %ld MB\n", get_ram() / 1024);
    
    int data_size = (l1 + 128) * 1024;
    data = (char*)malloc(data_size);
    if (!data) {
        return 1;
    }

    if (argc > 1 && argv[1][0] == '1') {
        setbuf(stdin, NULL);
        printf("Unbuffered>> ");
    }

    while ((c = getchar()) != EOF && (num <= MAXN)) {
        if ((num * 10 + (c - '0') <= MAXN) && isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '\n') {
            break;
        } else {
            break;
        }
    }
    
    printf("\tInput number: %d\n", num);
    
    for (int i = 1; i <= num; i++) {
        sum += i;
        memory[i % 65536] = i % 256;
        data[i % data_size] = (sum + i) % 256;
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
    
    printf("Sum of 1 to %d = ", num);
    while (index > 0) {
        putchar(buffer[--index]);
    }
    putchar('\n');
    
    free(data);
    return 0;
}