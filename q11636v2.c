#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11636.in", "r", stdin);
	freopen("q11636.out", "w", stdout);
	#endif

	int targetLines, existLines, pasteTimes, currentCase = 0;
	while(scanf("%d", &targetLines)!=EOF && targetLines > 0){
		existLines = 1, pasteTimes = 0;
		while(targetLines > existLines){
			existLines = existLines << 1;
			pasteTimes++;
		}
		printf("Case %d: %d\n", ++currentCase, pasteTimes);
	}
	return 0;
}
