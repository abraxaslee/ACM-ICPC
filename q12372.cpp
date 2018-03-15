//q12372.cpp - 2011/12/06
//accepted at 
//run time = 0.008
#include <stdio.h>

int main(){


	int T, L, W, H, CaseNum = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &L, &W, &H);
		printf("Case %d: ", ++CaseNum);
		if(L > 20 || W > 20 || H > 20)
			puts("bad");
		else
			puts("good");
	}
	return 0;
}
