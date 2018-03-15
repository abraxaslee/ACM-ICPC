//q382.cpp - 2011/11/02
//accepted at
//run time = 0.008 c
#include <stdio.h>

int sum[60001] = {};

void solve(int n){
	if(sum[n] != 0)
		return;

	for(int i=1;i<=n/2;++i){
		if(n%i == 0)
			sum[n] += i;
	}
	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q382.in", "r", stdin);
	freopen("q382.out", "w", stdout);
	#endif

	sum[1] = -9999;
	int tmp;
	puts("PERFECTION OUTPUT");
	while(scanf("%d", &tmp)!=EOF && tmp > 0){
		solve(tmp);

		if(sum[tmp]==tmp)
			printf("%5d  PERFECT\n", tmp);
		else if(sum[tmp]>tmp)
			printf("%5d  ABUNDANT\n", tmp);
		else
			printf("%5d  DEFICIENT\n", tmp);
	}
	puts("END OF OUTPUT");
	return 0;
}
