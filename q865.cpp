//q865.cpp - 2011/10/23
//accepted at 
//run time = 0.008
#include <stdio.h>

char buff[100];
char plain[300];
char sub[300];
int decode[300];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q865.in", "r", stdin);
	freopen("q865.out", "w", stdout);
	#endif

	int caseNum, i, once = 0;
	scanf("%d", &caseNum); getchar(); getchar();
	while(caseNum--){
		gets(plain);
		gets(sub);

		for(i=0; i<300; ++i)
			decode[i] = i;
		for(i=0; plain[i] != '\0'; ++i)
			decode[plain[i]] = sub[i];

		if(once)
			putchar(10);

		puts(sub);
		puts(plain);

		while(gets(buff)!=NULL && buff[0] != '\0'){
			for(i=0; buff[i] != '\0'; ++i)
				putchar(decode[buff[i]]);
			putchar(10);
		}
		once = 1;
	}
	return 0;
}

