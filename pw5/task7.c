#include <stdio.h>
#include <string.h>

#define LEN 1000

int main() {
	char s[LEN];
	scanf("%s", s);
	for(int i = strlen(s); i>=0; i--){
		printf("%c", s[i]);
	} 	
	return 0;
}
