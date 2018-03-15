//q11799.cpp - 2011/10/21
//accepted at 
//run time = 0.004
#include <stdio.h>


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11799.in", "r", stdin);
	freopen("q11799.out", "w", stdout);
	#endif

	int max, tmp, caseNum, creatureNum, i, currentCase=0;
	scanf("%d", &caseNum);
	while(caseNum--){
		max = 0;
		scanf("%d", &creatureNum);
		for(i=0;i<creatureNum;i++){
			scanf("%d", &tmp);
			max = (tmp > max) ? tmp : max;
		}
		printf("Case %d: %d\n", ++currentCase, max);
	}

	return 0;
}
