//2012/02/27
//11287.cpp
//Run time: 0.004
#include <stdio.h>

int P, A, mA;

int isPrime(int x){
	if(x % 2 == 0)	return 0;

	int i;
	for(i=3; i*i <= x; i+=2)
		if(x % i == 0)	return 0;
	return 1;
}

long long int bigMod(int index){
	if(index == 0)	return 1;
	if(index == 1)	return mA;

	long long int temp = bigMod(index/2);
	temp = (temp * temp) % P;
	if(index & 1)
		return (temp * mA) % P;
 	return temp;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("11287.in", "r", stdin);
	freopen("11287.out", "w", stdout);
	#endif

	while(scanf("%d%d", &P, &A) == 2){
			if(P + A == 0)	break;

	    	if(isPrime(P) == 1){
	    		puts("no"); continue;
	    	}
	    	mA = A % P;
	    	if(bigMod(P) == mA)
	    		puts("yes");
	    	else
	    		puts("no");
		}

	return 0;
}
