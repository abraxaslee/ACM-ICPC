//q10970.cpp - 2011/11/21
//accepted at 
//run time = 0.036
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10970.in", "r", stdin);
	freopen("q10970.out", "w", stdout);
	#endif

	int m, n;
	while(scanf("%d%d",&m,&n)==2){
		printf("%d\n", m*n-1);
	}
	return 0;
}
