//q10023.cpp - 2011/11/14
//accepted at 
//run time = 
#include <stdio.h>
#include <math.h>

int main(){
	int n;
	long double X;
	scanf("%d", &n);
	while(n--){
		scanf("%Lf", &X);
		printf("%.0Lf\n", sqrtl(X));
	}
	return 0;
}
