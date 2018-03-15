//q568.cpp - 2011/11/25
//accepted at 
//run time = 0.012
#include <stdio.h>
int lastDigit[10001];

void getLast(int n){

	lastDigit[n] = lastDigit[n-1] * n;

	while(lastDigit[n] %10 == 0)
		lastDigit[n] /= 10;

	lastDigit[n] %= 100000;
	return;
}

void build_Last(){
	lastDigit[0] = 1;
	lastDigit[1] = 1;
	int i;
	for(i=2;i<10001;++i)
		getLast(i);
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q568.in", "r", stdin);
	freopen("q568.out", "w", stdout);
	#endif

	int n; build_Last();
	while(scanf("%d", &n)!=EOF){
		printf("%5d -> %d\n", n, lastDigit[n]%10);
	}
	return 0;
}
