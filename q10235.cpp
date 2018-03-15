//q10235.cpp - 2011/11/23
//accepted at 
//run time = 
#include <stdio.h>
#define MAX 1000000
#define sqrt_MAX 1000

bool sieve[MAX +1];
int prime[78500];
int primeTop;

void sieve_table(){
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

int binarySearch(int search){
	int low = 0, high = 78498;
	int mid;

	while(low <= high){

		mid = (low + high)/2;

		if(prime[mid] == search)
			return mid;
		else if(search > prime[mid])
			low = mid + 1;
		else if(prime[mid] > search)
			high = mid - 1;

	}

	return -1;
}

int reverse(int inputNum){
	int result = 0;
	while(inputNum > 0){
		result *= 10;
		result += inputNum%10;
		inputNum /= 10;
	}
	return result;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10235.in", "r", stdin);
	freopen("q10235.out", "w", stdout);
	#endif


	sieve_table();
	output_prime();
	int N, reN;
	while(scanf("%d", &N) != EOF){
		if( binarySearch(N) >= 0){
			reN = reverse(N);
			if(reN != N && binarySearch(reN) >= 0)
				printf("%d is emirp.\n", N);
			else
				printf("%d is prime.\n", N);
		}else{
			printf("%d is not prime.\n", N);
		}
	}
	return 0;
}
