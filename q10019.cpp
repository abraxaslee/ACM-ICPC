//q10019.cpp - 2011/09/16
//Q10019 : Funny Encryption Method
//accepted at 2011-09-16 08:47:20
//run time = 0.008
#include <stdio.h>
#include <math.h>
using namespace std;

int bitCount(int);
int tenToSixteen(int);

int main(){
	int caseNum = 0;
	scanf("%d", &caseNum);

	caseStart:
	int numN = 0;
	scanf("%d", &numN);

	printf("%d %d\n", bitCount(numN), bitCount(tenToSixteen(numN)));
	caseNum = caseNum - 1;
	if(caseNum == 0){return 0;}
	goto caseStart;
	return 0;
}

int bitCount(int inputNum){
	int bitCounter = 0;
	while(inputNum>0){
		if(inputNum &1){
			bitCounter +=1;
		}
		inputNum = inputNum >> 1;
	}
	return bitCounter;
}

int tenToSixteen(int inputNum){
	int outputNum = 0;
	for(int i =0;inputNum > 0 ;i++){
		outputNum += (inputNum%10)*pow(16,i);
		inputNum = inputNum / 10;
	}
	return outputNum;
}

