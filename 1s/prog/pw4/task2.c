#include  <stdio.h>

int main(){
	int number = 0;
	printf("chislo ");
	scanf("%d", &number);
	for(int i = number; i <=number+10; i++){
		printf("%d ",i); 
	}
return 0;
}
