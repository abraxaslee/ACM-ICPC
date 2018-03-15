//q11577.cpp - 2011/11/21
//accepted at 
//run time = 
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11577.in", "r", stdin);
	freopen("q11577.out", "w", stdout);
	#endif

	int caseNum, i, c, top, max;
	int output[30];
	scanf("%d", &caseNum);
	getchar();
	while(caseNum--){

		int words[300] = {};
		top = 0, max = -1;
		while( (c = getchar()) && c != 10 ){
			words[c] += 1;
		}

		for(i=65;i<=90;++i)
			words[32+i] += words[i];

		for(i=97;i<=122;++i){
			if(words[i] > max){
				top = 0;
				output[top++] = i;
				max = words[i];
			}else if(words[i] == max)
				output[top++] = i;
		}

		for(i=0;i<top;++i)
			putchar(output[i]);

		putchar(10);

	}
	return 0;
}
