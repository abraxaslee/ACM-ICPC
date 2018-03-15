//q594.cpp - 2011/09/17
//accepted at 
//run time = 0.016
#include <stdio.h>
using namespace std;

int main(){
	int little, big;
	char* plittle = (char*)&little;
	char* pbig = (char*)&big;
	caseStart:
	if(scanf("%d", &little)!=1){return 0;}
	pbig[0] = plittle[3];
	pbig[1] = plittle[2];
	pbig[2] = plittle[1];
	pbig[3] = plittle[0];
	printf("%d converts to %d\n", little, big);
	goto caseStart;
	return 0;
}
