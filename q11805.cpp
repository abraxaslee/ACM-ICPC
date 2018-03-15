//q11805.cpp - 2011/12/04
//accepted at 
//run time = 0.008
#include <stdio.h>

int main(){

	int caseNum, currentCase = 0, N, K, P, tmp;
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d%d%d", &N, &K, &P);
		tmp = (K+P)%N;
		if(tmp)
			printf("Case %d: %d\n", ++currentCase, tmp);
		else
			printf("Case %d: %d\n", ++currentCase, N);
	}

	return 0;
}
