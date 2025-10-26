#include <stdio.h>

int main(){
	char c = getchar();
	char a = 'A';
	

        for(int i = 0; i<= c-a; i++){
        	
		for(int j = 0; j < c-a-i; j++){
			printf(" ");
		}
		
		for(int k = 0; k <= i; k++){
			printf("%c", a+k);
		}
		
		for(int l = i-1; l>=0;l--){
			printf("%c", a+l); 
		}	
		
		printf("\n");
	}

        return 0;
}
