//q10127.cpp - 2011/11/13
//accepted at 
//run time = 
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10127.in", "r", stdin);
	freopen("q10127.out", "w", stdout);
	#endif

	int inputNum, ones, i;
	while(scanf("%d", &inputNum)!=EOF){
		if(inputNum == 0){
			puts("0");
			continue;
		}

		ones = 1%inputNum, i = 1;

		while(ones != 0){
			ones = (ones * 10) +1;
			ones %= inputNum;
			++i;
		}
		printf("%d\n", i);
	}
	return 0;
}
