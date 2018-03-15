//q10929.cpp - 2011/09/14
//Q10929: You can say 11
//accepted at 2011-09-14 13:04:27
//run time = 0.016
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	char inputNum[1001];
	gameStart:
	scanf("%s", inputNum);
	if(inputNum[0]=='0'){return 0;}
	int z = strlen(inputNum);
	unsigned int oddSum = 0, evenSum = 0;
	for(int i=0;i<z;i++){
		if(i&1){
			oddSum += inputNum[i]-48;
		}else{
			evenSum += inputNum[i]-48;
		}
	}
	int temp = ((oddSum - evenSum)>0)?(oddSum - evenSum):(evenSum - oddSum);
	if(temp){
		if((temp%11)==0){
			printf("%s is a multiple of 11.\n", inputNum);
		}else{
			printf("%s is not a multiple of 11.\n", inputNum);
		}
	}else{
		printf("%s is a multiple of 11.\n", inputNum);
	}
	goto gameStart;
	return 0;
}
