//q10473.cpp - 2011/09/10
//accepted at 2011-09-10 13:51:02
//run time = 0.016
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

int main(){
	unsigned int iNum = 0;
	char inputString[12];
	while(true){
		scanf("%s", inputString);
		if(inputString[0]=='-'){break;}
		if(inputString[1]=='x'){
			iNum = 0;
			for(int i=strlen(inputString)-1,m=strlen(inputString)-1;i>1;i--){
				inputString[i]-=48;
				if(inputString[i]>9){inputString[i]-=7;}
				//printf("%d + %d * 16 ^ %d\n", iNum, inputString[i], m-i);
				iNum += (inputString[i])*pow(16,m-i);
			}
			printf("%d\n", iNum);
		}else{
			iNum = atoi(inputString);
			printf("0x%X\n", iNum);
		}
	}
	return 0;
}
