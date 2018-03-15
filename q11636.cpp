//q11636.cpp - 2011/10/21
//accepted at 
//run time = 0.020 / 0.004 c
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11636.in", "r", stdin);
	freopen("q11636.out", "w", stdout);
	#endif

	int targetLines, existLines, pasteTimes, currentCase = 0;
	while(scanf("%d", &targetLines)!=EOF && targetLines > 0){
		existLines = 1, pasteTimes = 0;
		while(existLines < targetLines){
			if((targetLines - existLines) > existLines){
				existLines *= 2;
				pasteTimes += 1;
				continue;
			}else{
				pasteTimes += 1;
				break;
			}
		}
		printf("Case %d: %d\n", ++currentCase, pasteTimes);
	}
	return 0;
}
