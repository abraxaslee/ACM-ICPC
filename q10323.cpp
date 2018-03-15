//q10323.cpp - 2011/11/08
//accepted at 
//run time = 0.012
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10323.in", "r", stdin);
	freopen("q10323.out", "w", stdout);
	#endif

	int n;
	while(scanf("%d", &n)!=EOF){
		if( n < 0){
			if( n & 1)
				puts("Overflow!");
			else
				puts("Underflow!");

			continue;
		}
		if( n < 8 ){
			puts("Underflow!");
			continue;
		}
		if( n > 13){
			puts("Overflow!");
			continue;
		}
		switch(n){
			case 8:
				puts("40320");
				break;

			case 9:
				puts("362880");
				break;

			case 10:
				puts("3628800");
				break;

			case 11:
				puts("39916800");
				break;

			case 12:
				puts("479001600");
				break;

			case 13:
				puts("6227020800");
				break;
		}
	}
	return 0;
}
