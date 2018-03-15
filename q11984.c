//q11984.c - 2011/10/13
//accepted at 
//run time = 0.004
#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11984.in", "r", stdin);
	freopen("q11984.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0;
	double C, D, tmp;
	scanf("%d", &caseNum);
	while(caseNum-- > 0){
		scanf("%lf %lf", &C, &D);
		tmp = D *5 /9;
		C += tmp;
		printf("Case %d: %.2f\n", ++currentCase, C);
	}
	return 0;
}

