#include <stdio.h>
#define HOUR 60
int main(void){
	int time = 1;

	while(time>0){
		printf("vremya v minytah ");
		scanf("%d", &time);

		printf("%d hours %d mins", time/HOUR, time%HOUR);
	}
}
