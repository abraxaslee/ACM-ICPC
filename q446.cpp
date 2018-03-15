//q446.cpp - 2011/09/23
//accepted at 2011-09-23 01:56:46
//run time = 0.008
#include <stdio.h>
using namespace std;

void getBinaryBits(int inputNum){
	bool BITS[13] = {false};
	for(int i=12;i>=0;i--){
		if(inputNum&1){
			BITS[i] = true;
		}
		inputNum = inputNum >> 1;
	}
	for(int i=0;i<13;i++){
		printf("%d", (int)BITS[i]);
	}
}

int main(){
	int HEX1, HEX2, caseNum;
	char Sign;

	scanf("%d", &caseNum);
	caseStart:
	scanf("%X %c %X", &HEX1, &Sign, &HEX2);
	getBinaryBits(HEX1);
	printf(" %c ", Sign);
	getBinaryBits(HEX2);
	if(Sign=='+'){
		printf(" = %d\n", HEX1 + HEX2);
	}else{
		printf(" = %d\n", HEX1 - HEX2);
	}
	if(--caseNum>0){
		goto caseStart;
	}
	return 0;
}
