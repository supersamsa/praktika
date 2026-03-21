#include <stdio.h>

int scount, ncount, acount;

int main(){
	
	char read_c;

	while((read_c = getchar())!='#')
	{
		if(read_c == ' '){scount++;}
		else if(read_c == '\n'){ncount++;}
		else{acount++;}
	}
	
	printf("%d space, %d \\n,%d other", scount, ncount, acount);

	return 0;
}

