//q10696.cpp - 2011/09/14
//accepted at 
//run time = 0.196
#include <stdio.h>
using namespace std;

unsigned int f91(int);

int main(){
	unsigned int uiNum = 0;
	caseStart:
	scanf("%u", &uiNum);
	if(uiNum == 0){ return 0 ;}
	printf("f91(%u) = %u\n", uiNum, f91(uiNum));
	goto caseStart;
	return 0;
}

unsigned int f91(int N){
	if(N>100){
		return (N-10);
	}else{
		return f91(f91(N+11));
	}
}
