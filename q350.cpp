//q350.cpp - 2011/10/21
//accepted at 
//run time = 0.012
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q350.in", "r", stdin);
	freopen("q350.out", "w", stdout);
	#endif

	int Z, I, M, L, cycle, caseNum = 0;
	unsigned int tmp;
	while(scanf("%d%d%d%d", &Z, &I, &M, &L)!=EOF && Z+I+M+L > 0){
		int done[10000] = {};
		for(tmp = (( L % M ) * (Z %M) + (I%M))%M, cycle = 0; done[tmp] == 0; ++cycle){
			done[tmp] = 1;
			tmp = (( tmp % M ) * (Z %M) + (I%M))%M;
		}
		printf("Case %d: %d\n", ++caseNum, cycle);
	}
	return 0;
}
