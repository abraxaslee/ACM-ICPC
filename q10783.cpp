//q10783.cpp - 2012/01/06
//accepted at 
//run time = 0.004
#include <stdio.h>


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10783.in", "r", stdin);
	freopen("q10783.out", "w", stdout);
	#endif

	int testcase, a, b, count, current = 0, ans;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d%d", &a, &b);
		if(a == b){
			printf("Case %d: ", ++current);
			if(a & 1)
				printf("%d\n", a);
			else
				puts("0");
			continue;
		}

		if(!(b & 1))
			b--;
		if(!(a &1))
			a++;

		count = (b - a)/2 +1;
		ans = (b + a) * count / 2;
		printf("Case %d: %d\n", ++current, ans < 0 ? 0 : ans);
	}
	return 0;
}
