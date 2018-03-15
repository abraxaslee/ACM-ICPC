//q100v2.cpp - 2011/11/12
//accepted at 
//run time = 0.020
#include <stdio.h>
#define even(x) x>>1
#define odd(x) even((3*x)+1)
#define SIZE 1000001
int dp[SIZE];

int max(int A, int B){
	return (A > B)? A : B;
}

void swap(int* A, int* B){
	int temp = *A;
	*A = *B;
	*B = temp;
}

int cycLength(unsigned long int n){

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

int findCyc(int n, int m){
	int maxNum = 0;

	if(n > m)
		swap(&n, &m);

	while(n<=m){
		maxNum = max(maxNum, cycLength(n++));
	}
	return maxNum;
}

int main(){

	dp[1] = 1;

	int n, m;
	while(scanf("%d%d", &n, &m)!=EOF){
		printf("%d %d %d\n", n, m, findCyc(n,m));
	}
	return 0;
}
