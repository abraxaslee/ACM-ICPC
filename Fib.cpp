#include <stdio.h>

int Fib[5001][120] = {};
int top[5001] = {};

void BigAdd(int n){
	int i;
	for(i=0 ;Fib[n-1][i] + Fib[n-2][i] > 0 ;++i){
		Fib[n][i] += Fib[n-1][i] + Fib[n-2][i];
		if(Fib[n][i] > 1000000000){
			Fib[n][i+1] += Fib[n][i]/1000000000;
			Fib[n][i] %= 1000000000;
		}
	}
	while(Fib[n][i] > 0){
		i++;
	}
	top[n] = i;
	return;
}

void buildTable(void){
	for(int i=3;i<=5000;++i){
		BigAdd(i);
	}
	return;
}

void getBigNum(int n){
	printf("Fib[%d] = ", n-2);

	printf("%d", Fib[n][top[n]-1]);
	for(int i = top[n]-2; i>=0 ;--i){
		printf("%09d", Fib[n][i]);
	}
	printf(";\n");
	return;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("fib.out", "w", stdout);
	#endif

	Fib[0][0] = 0; top[0] = 1;
	Fib[1][0] = 1; top[1] = 1;
	Fib[2][0] = 1; top[2] = 1;
	buildTable();

	int inputNum;
	for(int i=2;i<=60;++i)
		getBigNum(i);

	return 0;
}
