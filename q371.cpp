//q371.cpp - 2011/11/12
//accepted at 
//run time = 0.052 / 0.044 c
#include <stdio.h>
#define even(x) x>>1
#define odd(x) even((3*x)+1)
#define SIZE 7900000
int dp[SIZE];

int maxNum, who;

void swap(int* A, int* B){
	int temp = *A;
	*A = *B;
	*B = temp;
}

inline int cycLength(unsigned long long int n){

	if( n < SIZE && dp[n] != 0 )
		return dp[n];

	if( n & 1){

		if( n < SIZE){
			dp[n] = 2 + cycLength(odd(n));
			return dp[n];
		}else{
			return 2 + cycLength(odd(n));
		}

	}else{

		if( n < SIZE){
				dp[n] = 1 + cycLength(even(n));
				return dp[n];
		}else{
			return 1 + cycLength(even(n));
		}
	}

	return 0;
}

void findCyc(int n, int m){
	int tmp;

	if( n == 1 ){
		who = 1;
		maxNum = 4;
		n = 2;
	}

	while(n<=m){
		tmp = cycLength(n);
		if( tmp > maxNum){
			maxNum = tmp;
			who = n;
		}
		++n;
	}
	return;
}

int main(){

	dp[1] = 1;

	int n, m;
	while(scanf("%d%d", &n, &m)!=EOF && n > 0 && m > 0){
		who = 0, maxNum = 0;

		if(n > m)
			swap(&n, &m);

		findCyc(n,m);

		printf("Between %d and %d, %d generates the longest sequence of %d values.\n", n, m, who, maxNum-1);
	}
	return 0;
}
