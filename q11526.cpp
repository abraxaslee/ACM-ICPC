//q11526.cpp - 2012/01/04
//accepted at 
//run time = 0.072
#include <stdio.h>
#include <math.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11526.in", "r", stdin);
	freopen("q11526.out", "w", stdout);
	#endif

	int caseNum, i, sq, n;
	long long int ans;
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d", &n);
		sq = (int)(sqrt(n));
		ans = 0;
		for(i=1; i<=sq; ++i)
			ans += n/i;
		ans = 2*ans - sq*sq;
		printf("%lld\n", ans);
	}
	return 0;
}
