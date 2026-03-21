#include <stdio.h>

int main(){
        for(int i = 0; i< 6; i++){
		char c = 'F';
		for(int j = 0; j<=i; j++){
                        printf("%c", c-j);
                }
                printf("\n");
        }

        return 0;
}
