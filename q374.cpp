//q374.cpp - 2011/11/21
//accepted at 
//run time = 0.004 c
#include <stdio.h>

unsigned int B, P, mod;

unsigned int bigMod(unsigned int index){
	if(index == 0)
		return 1;
	else if(index == 1)
		return B;
	else if(index == 2)
		return B*B %mod;

	if(index %2 == 0){
		unsigned int tmp = bigMod(index/2);
		return (tmp * tmp) % mod;
	}else{
		unsigned int tmp = bigMod((index-1)/2);
		return ((tmp * tmp) % mod *B)%mod;
	}
	return 0;
}


int main(){

	while(scanf("%u%u%u", &B, &P, &mod)==3){
		B %= mod;
		printf("%u\n", bigMod(P));
	}
	return 0;
}
