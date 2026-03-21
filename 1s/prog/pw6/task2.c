#include <stdio.h>


int main(){

        char read_c;
	int count;
        while((read_c = getchar())!='#')
	{	
		printf("%d %c ", read_c, read_c);
		count++;
		if(count%8==0)
			printf("\n");
        }

        return 0;
}

