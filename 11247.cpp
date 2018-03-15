//2012/02/26
//11247.cpp
//Run time:

#include <stdio.h>


int main(){

	#ifndef ONLINE_JUDGE
	freopen("11247.in", "r", stdin);
	freopen("11247.out", "w", stdout);
	#endif

	int M, X;
	while(scanf("%d%d", &M, &X) == 2){
		if(M + X == 0)	break;
		if(M == 1 || X == 0 || X == 100){
			puts("Not found");	continue;
		}
		long long int V = 100 * (M - 1);

	}
	return 0;
}
