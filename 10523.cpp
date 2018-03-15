//2012/01/11
//10523.cpp
//Run time: 0.024

#include <stdio.h>
#define CARRY 1000000

int top;
void multi(int bigNum[], int n){
	int i;
	for(i=0; i<top; ++i)
		bigNum[i] *= n;
	for(i=0; i<top; ++i){
		if(bigNum[i] >= CARRY){
			bigNum[i+1] += bigNum[i]/CARRY;
			bigNum[i] %= CARRY;
		}
	}
	while(bigNum[top]){
		top++;
	}
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10523.in", "r", stdin);
	freopen("10523.out", "w", stdout);
	#endif

	int i, n, A;
	while(scanf("%d%d", &n, &A)==2){
		top = 1;
		int bigNum[35] = {};
		for(i=n; i>=0; --i){
			multi(bigNum, A);
			bigNum[0] += i;
		}
		printf("%d", bigNum[top-1]);
		for(i=top-2; i>=0; --i)
			printf("%06d", bigNum[i]);
		putchar(10);
	}
	return 0;
}
