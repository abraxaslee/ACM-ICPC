//q10019v2.cpp - 2011/11/12
//accepted at 
//run time = 
#include <stdio.h>

char buff[10];

int bitCount(int inputNum){
	int bitCounter = 0;
	while(inputNum>0){
		if(inputNum & 1){
			++bitCounter;
		}
		inputNum = inputNum >> 1;
	}
	return bitCounter;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10019.in", "r", stdin);
	freopen("q10019.out", "w", stdout);
	#endif

	int caseNum, hex, dec;
	scanf("%d\n", &caseNum);
	while(caseNum--){
		gets(buff);
		sscanf(buff, "%d", &dec);
		sscanf(buff, "%X", &hex);
		printf("%d %d\n", bitCount(dec), bitCount(hex));
	}
	return 0;
}
