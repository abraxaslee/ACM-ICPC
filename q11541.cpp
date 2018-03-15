//q11541.cpp - 2011/11/02
//accepted at 
//run time = 
#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11541.in", "r", stdin);
	freopen("q11541.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0, c, digit, i;
	scanf("%d", &caseNum);
	getchar();
	digit = 0; c = 0;
	while(caseNum--){
		printf("Case %d: ", ++currentCase);
		while(true){
			c=getchar();
			if(c==10){
				break;
			}
			scanf("%d", &digit);
			for(i=0;i<digit;++i)
				putchar(c);
		}
		putchar(10);
	}
	return 0;
}
