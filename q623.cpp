//q623.cpp - 2011/11/17
//accepted at 
//run time = 0.048
#include <stdio.h>
#define CARRY 1000000
#define MAXDIGIT 500

int factorial[1001][MAXDIGIT];
int top[1001];

void setFactorial(int n){
	int i;
	//printf("DEBUG: seting %d!\n", n);

	for(i = 0 ; i < top[n-1] ; ++i){
		factorial[n][i] += factorial[n-1][i] * n;
		//printf("DEBUG: factorial[%d][%d] += factorial[%d][%d] * %d = %d\n", n, i, n-1, i, n, factorial[n-1][i] * n );
		if(factorial[n][i] >= CARRY){
			factorial[n][i+1] += factorial[n][i] / CARRY;
			factorial[n][i] %= CARRY;
		}
	}


	while(factorial[n][i] > 0){
		i += 1;
	}
	top[n] = i;
	//printf("DEBUG: top[%d] = %d\n", n, top[n]);
	return;
}

void getFactorial(int n){
	int i;
	printf("%d!\n", n);

	printf("%d", factorial[n][top[n]-1]);
	for(i = top[n]-2 ;i >= 0 ; --i)
		printf("%06d", factorial[n][i]);

	putchar(10);

	return;
}

void build_Factorial(){
	int i;

	factorial[0][0] = 1;
	top[0] = 1;

	factorial[1][0] = 1;
	top[1] = 1;

	factorial[2][0] = 2;
	top[2] = 1;

	for(i = 3 ; i < 1001; ++i)
		setFactorial(i);

	return;
}
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q623.in", "r", stdin);
	freopen("q623.out", "w", stdout);
	#endif

	build_Factorial();
	int input;
	while(scanf("%d", &input) != EOF){
		getFactorial(input);
	}
	return 0;
}
