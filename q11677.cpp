//q11677.cpp - 2011/12/24
//accepted at 
//run time = 0.004
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11677.in", "r", stdin);
	freopen("q11677.out", "w", stdout);
	#endif

	int HH[2], MM[2], ans;
	while(scanf("%d%d%d%d", &HH[0], &MM[0], &HH[1], &MM[1]) == 4){
		if(HH[0] + HH[1] + MM[0] + MM[1] == 0)	break;
		ans = HH[1] * 60 + MM[1];
		ans -= HH[0] *60 + MM[0];
		if(ans < 0)
			ans += 1440;

		printf("%d\n", ans);
	}

	return 0;
}
