//2012/02/25
//10006.cpp
//Run time: 0.024

#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10006.in", "r", stdin);
	freopen("10006.out", "w", stdout);
	#endif


	int input;
	while(scanf("%d", &input) == 1){
		if(input == 0)	break;
		if(input == 561)		puts("The number 561 is a Carmichael number.");
		else if(input == 1105)	puts("The number 1105 is a Carmichael number.");
		else if(input == 1729) 	puts("The number 1729 is a Carmichael number.");
		else if(input == 2465)	puts("The number 2465 is a Carmichael number.");
		else if(input == 2821)	puts("The number 2821 is a Carmichael number.");
		else if(input == 6601)	puts("The number 6601 is a Carmichael number.");
		else if(input == 8911)	puts("The number 8911 is a Carmichael number.");
		else if(input == 10585)	puts("The number 10585 is a Carmichael number.");
		else if(input == 15841)	puts("The number 15841 is a Carmichael number.");
		else if(input == 29341)	puts("The number 29341 is a Carmichael number.");
		else if(input == 41041)	puts("The number 41041 is a Carmichael number.");
		else if(input == 46657)	puts("The number 46657 is a Carmichael number.");
		else if(input == 52633)	puts("The number 52633 is a Carmichael number.");
		else if(input == 62745)	puts("The number 62745 is a Carmichael number.");
		else if(input == 63973)	puts("The number 63973 is a Carmichael number.");
		else printf("%d is normal.\n", input);
	}
	return 0;
}
