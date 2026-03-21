#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {

    int max_int = INT_MAX;
    printf("int: %d\n", max_int);
    printf("int+1: %d\n", max_int + 1);
    
    float small_float = FLT_MIN;
    float large_float = FLT_MAX;
    
    printf("min float: %e\n", small_float);
    printf("float/2: %e\n", small_float / 2);
    
    printf("max float: %e\n", large_float);
    printf("max flot *2: %e\n", large_float * 2);
    
    return 0;
}
