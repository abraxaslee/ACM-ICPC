//q11530.c - 2011/10/13
//accepted at 
//run time = 0.004
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11530.in", "r", stdin);
	freopen("q11530.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0;
	int words, c;
	scanf("%d", &caseNum);
	while(caseNum-- >0){
		words = 0;
		while(getchar(c) && c != 10){
			if(c==32){
				words += 1;
				continue;
			}
			c -= 96;
			while(c>3){
				c -= 3 ;
			}
			words += c;
		}
		printf("Case #%d: %d",++currentCase, words);
	}
	return 0;
}
