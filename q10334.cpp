//q10334.cpp - 2011/12/03
//accepted at 
//run time = 0.004
#include <stdio.h>
#define CARRY 1000000000

int Fib[1001][75] = {};
int top[1001] = {};

void BigAdd(int n){
	int i;
	for(i=0 ;Fib[n-1][i] + Fib[n-2][i] > 0 ;++i){
		Fib[n][i] += Fib[n-1][i] + Fib[n-2][i];
		if(Fib[n][i] >= CARRY ){
			Fib[n][i+1] += Fib[n][i]/CARRY;
			Fib[n][i] %= CARRY;
		}
	}
	while(Fib[n][i] > 0){
		i++;
	}
	top[n] = i;
	return;
}

void buildTable(void){
	Fib[0][0] = 1; top[0] = 1;
	Fib[1][0] = 2; top[1] = 1;
	Fib[2][0] = 3; top[2] = 1;
	int i;
	for(i=3;i<=1000;++i){
		BigAdd(i);
	}
	return;
}

void getBigNum(int n){
	printf("%d", Fib[n][top[n]-1]);
	int i;
	for(i = top[n]-2; i>=0 ;--i){
		printf("%09d", Fib[n][i]);
	}
	putchar(10);
	return;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10334.in", "r", stdin);
	freopen("q10334.out", "w", stdout);
	#endif

	buildTable();

	int input;
	while(scanf("%d", &input)!=EOF){
		getBigNum(input);
	}
	return 0;
}
