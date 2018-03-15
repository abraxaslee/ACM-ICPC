//q12149.cpp - 2012/01/06
//accepted at 
//run time = 0.012
#include <stdio.h>

int sum[101];

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q12149.in", "r", stdin);
	freopen("q12149.out", "w", stdout);
	#endif

	int i;
	for(i=1; i<=100; ++i)
		sum[i] = sum[i-1] + i*i;

	while(scanf("%d", &i)!=EOF){
		if(i == 0)	break;
		printf("%d\n", sum[i]);
	}
	return 0;
}
// 0.004
int main(){

	int n;
	while(scanf("%d", &n)!=EOF){
		if(n == 0)	break;
		printf("%d\n", n * (n+1) * (2*n +1) / 6);
	}
	return 0;
}
