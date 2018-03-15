//q11614.cpp - 2011/11/25
//accepted at 
//run time = 
#include <stdio.h>
#include <math.h>

int main(){
	/*
	#ifndef ONLINE_JUDGE
	freopen("q11614.in", "r", stdin);
	freopen("q11614.out", "w", stdout);
	#endif*/

	int caseNum;
	scanf("%d", &caseNum);
	unsigned long long int n;
	while(caseNum--){
		scanf("%llu", &n);
		printf("%llu\n", ceil(sqrt(1 + 4*n)/2));
	}
	return 0;
}
