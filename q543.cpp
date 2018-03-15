//q543.cpp - 2011/11/29
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
	for(int i=3;i<MAX;i++)
		if(i%2 > 0)
			if(!sieve[i])
				prime[primeTop++] = i;
	return;
}

int binarySearch(int search, int data[]){
	int low = 0, high = primeTop-1;
	int mid;

	while(low <= high){

		mid = (low + high)/2;

		if(data[mid] == search)
			return mid;
		else if(search > data[mid])
			low = mid + 1;
		else if(data[mid] > search)
			high = mid - 1;

	}

	return -1;
}

void solve(int n){
	int i = 0, bSearch;

	bSearch = binarySearch( n - prime[i], prime);
	while(bSearch < 0)
		bSearch = binarySearch( n - prime[++i], prime);

	printf("%d = %d + %d\n", n, prime[i], prime[bSearch]);
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q543.in", "r", stdin);
	freopen("q543.out", "w", stdout);
	#endif


	sieve_table();output_prime();
	int input;
	while(scanf("%d", &input)!=EOF){
		if(input == 0) break;
		solve(input);
	}
	return 0;
}
