#include <stdio.h>

double min(double x,double y);

int main(){
	printf("%.2lf", min(2.0,3.0));

	return 0;
}

double min(double x, double y){
	return x<y?x:y; 
}
