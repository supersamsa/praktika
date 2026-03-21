#include <stdio.h>
int s, f;
int main() {
	scanf("%d %d", &s,&f);
	printf("a---a^2----a^3\n");
	for(int i = s; i <=f; i++){
		printf("%d---%d----%d", i, i*i, i*i*i);
		printf("\n");
	}
	return 0;
}

