//2012/02/25
//11714.cpp
//Run time: 0.024

#include <stdio.h>
#include <math.h>
int main(){

	#ifndef ONLINE_JUDGE
	freopen("11714.in", "r", stdin);
	freopen("11714.out", "w", stdout);
	#endif

	unsigned int N;
	while(scanf("%u", &N) == 1)
		printf("%u\n", (N-1)+(unsigned int)(log(N-1)/log(2)));
	return 0;
}
