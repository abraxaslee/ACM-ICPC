//prime.cpp - 2011/11/19
//accepted at 
//run time =
#include <stdio.h>
#include <math.h>
#define MAX 1000000
#define sqrt_MAX sqrt(MAX)

bool sieve[MAX +1];
int prime[MAX];
int primeTop;

void prime_table(){
	for (int i=3; i<=sqrt_MAX; i+=2)
		if (!sieve[i])
			for (int j=i*i; j<MAX; j+=i*2)
				sieve[j] = true;
}

void output_prime(){
	for(int i=0;i<MAX;i++)
		if(i%2 > 0 || i == 2 )
			if(!sieve[i])
				prime[primeTop++] = i;
	return;
}

void primeNum(){
	int primeNum[1000] = {};
	for(int i=1,j=0; i <= 1000 ; i++)
		if(prime[j] <= i){
			primeNum[i] = primeNum[i-1] + 1;
			++j;
		}else
			primeNum[i] = primeNum[i-1];

	for(int i=0;i<=1000;i++)
		printf("primeNum[%d] = %d;\n", i, primeNum[i]);
	return;
}
int main(){

	prime_table();
	output_prime();
	printf("%d\n", prime[0]);
	printf("%d\n", prime[1]);
	printf("%d\n", prime[10001]);
	return 0;
}
