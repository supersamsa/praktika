#include <stdio.h>

int main(){
	 int time = 1;

        while(time>0){
                printf("dnei ");
                scanf("%d", &time);
	if(time>0){
                printf("%d дней составляют %d недели и %d дня.", time,  time/7, time%7);
        }

	}
	return 0;
}
