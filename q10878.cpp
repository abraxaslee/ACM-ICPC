//q10878.cpp - 2011/09/11
//accepted at 
//run time = 0.008
#include <stdio.h>
using namespace std;

int main(){
	char inputString[12];
	char outPutChar = 0;
	char outPutString[100000];
	bool flagEnding = false;
	int outPutIndex = 0;
	while(true){
		gets(inputString);
		if(inputString[0]=='_'){
			if(flagEnding){break;}
			flagEnding = true;
			continue;
		}
		outPutChar = 0;
		for(int i=2;i<6;i++){
			if(inputString[i]=='o'){
				outPutChar += 1 ;
			}
			outPutChar = outPutChar << 1;
		}
		for(int i=7;i<9;i++){
			if(inputString[i]=='o'){
				outPutChar += 1 ;
			}
			outPutChar = outPutChar << 1;
		}
		if(inputString[9]=='o'){
			outPutChar += 1 ;
		}
		outPutString[outPutIndex] = outPutChar;
		outPutIndex += 1;
	}
	printf("%s", outPutString);
	return 0;
}
