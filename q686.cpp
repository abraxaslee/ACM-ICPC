//q686.cpp - 2011/12/04
//accepted at 
//run time = 
#include <stdio.h>
#define MAX 33124
#define sqrt_MAX 182

bool sieve[MAX +1];
int prime[3555];
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
	int i, ans = 0, bSearch;

	for(i=0; prime[i] < n ; ++i){
		bSearch = binarySearch(n - prime[i], prime);
		if(bSearch >= 0){
			ans++;
			//printf("%d = %d + %d\n", n, prime[i], prime[bSearch]);
		}
	}
	if(ans == 1)
		printf("%d\n", ans);
	else if(ans %2)
		printf("%d\n", ans/2 +1);
	else
		printf("%d\n", ans/2);
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q686.in", "r", stdin);
	freopen("q686.out", "w", stdout);
	#endif


	sieve_table();output_prime();
	int input;
	while(scanf("%d", &input)!=EOF){
		if(input == 0) break;
		if(input == 4) {puts("1"); continue;}
		solve(input);
	}
	//printf("primeTop : %d\n", primeTop);
	return 0;
}
