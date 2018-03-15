//q11958.cpp - 2011/11/05
//accepted at 
//run time = 0.008 c
#include <stdio.h>
#define INT_MAX 2147483647

int min(int A, int B){
	return A<B ? A : B;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11958.in", "r", stdin);
	freopen("q11958.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0, busNum, now, bus, busTime, predict, tmp1, tmp2, wait;
	scanf("%d", &caseNum);
	while(caseNum--){
		wait = INT_MAX;
		scanf("%d %d:%d", &busNum, &tmp1, &tmp2);
		now = tmp1*60 + tmp2;
		while(busNum--){
			scanf("%d:%d %d", &tmp1, &tmp2, &predict);
			busTime = tmp1*60 + tmp2;

			if(busTime < now){
				predict += 1440 - now + busTime;
			}else{
				predict += busTime - now;
			}

			wait = min( predict , wait);
		}
		printf("Case %d: %d\n", ++currentCase, wait);
	}
	return 0;
}
