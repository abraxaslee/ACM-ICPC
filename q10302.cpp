//q10302.cpp - 2011/11/13
//accepted at 
//run time = 0.004 c

#include <stdio.h>
int main(){

	long long int x, result;

	while(scanf("%lld", &x)!=EOF){

		result = (x + 1) * x / 2;

		printf("%lld\n", result * result);
	}
	return 0;
}
