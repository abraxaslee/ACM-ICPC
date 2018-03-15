//q10550.cpp - 2011/12/12
//accepted at 
//run time = 0.008
#include <stdio.h>

int diff(int A){
	return A < 0 ? A+40 : A;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10550.in", "r", stdin);
	freopen("q10550.out", "w", stdout);
	#endif

	int zero, first, second, third;
	while(scanf("%d%d%d%d", &zero, &first, &second, &third) != EOF){
		if(zero == 0 && first == 0 && second == 0 && third == 0)	break;
		printf("%d\n", 1080+(diff(zero-first)*9)+(diff(second-first)*9)+(diff(second-third)*9));
	}
	return 0;
}
