//q10013.cpp - 2011/11/16
//accepted at 
//run time = 1.116c
#include <stdio.h>

int bigNum[1000005];
int top;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10013.in", "r", stdin);
	freopen("q10013.out", "w", stdout);
	#endif

	int caseNum, tmp1, tmp2, i, once = 0;
	scanf("%d", &caseNum);

	while(caseNum--){
		scanf("%d", &top);
		for(i=top-1;i>=0;--i){
			scanf("%d %d", &tmp1, &tmp2);
			bigNum[i] = tmp1 + tmp2;
		}

		for(i=0;i<top;++i){
			if( bigNum[i] >= 10 ){
				bigNum[i+1] += 1;
				bigNum[i] -= 10;
			}
		}

		if(once){
			putchar(10);
		}

		for(i=top-1;i>=0;--i){
			printf("%d", bigNum[i]);
		}
		putchar(10);

		once = 1;
	}
	return 0;
}
