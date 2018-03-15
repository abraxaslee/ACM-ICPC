//q10469.cpp - 2011/10/01
//accepted at 2011-10-01 14:12:02
//run time = 0.008
#include <stdio.h>

int main(){
	
	unsigned int uNum1, uNum2;
	while(scanf("%u %u", &uNum1, &uNum2)==2){
		printf("%u\n", uNum1^uNum2);
	}
	return 0;
}
