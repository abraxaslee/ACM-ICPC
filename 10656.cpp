//2012/03/26
//10656.cpp
//Run time: 0.020

#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10656.in", "r", stdin);
	freopen("10656.out", "w", stdout);
	#endif

	int i, N, temp, outflag;
	while(scanf("%d", &N) == 1){

		if(N == 0)	break;

		for(outflag = i = 0; i < N; ++i){
			scanf("%d", &temp);
			if(temp > 0){
				printf("%d", temp);
				outflag = 1;
				++i;
				break;
			}
		}

		while(i<N){
			scanf("%d", &temp);
			if(temp > 0)	printf(" %d", temp);
			++i;
		}

		if(outflag == 0) putchar('0');
		putchar(10);
	}

	return 0;
}
