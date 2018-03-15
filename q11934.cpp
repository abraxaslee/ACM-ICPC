//q11934.cpp - 2011/12/28
//accepted at 
//run time = 0.008
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11934.in", "r", stdin);
	freopen("q11934.out", "w", stdout);
	#endif

	int a, b, c, d, L, i, ans;
	while(scanf("%d%d%d%d%d", &a, &b, &c, &d, &L)!=EOF){
		ans = 0;
		if(a+b+c+d+L == 0)	break;
		for(i=0; i<=L; ++i)
			if((a*i*i + b*i + c) % d == 0)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
