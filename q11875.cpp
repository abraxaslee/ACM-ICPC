//q11875.cpp - 2011/11/21
//accepted at 
//run time = 0.004 c
#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11875.in", "r", stdin);
	freopen("q11875.out", "w", stdout);
	#endif

	int caseNum, current = 0, i, member;
	char buff[100];
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d ", &member);
		gets(buff);
		member /= 2;
		member *= 3;
		printf("Case %d: %c%c\n", ++current, buff[member], buff[member+1]);
	}

	return 0;
}

