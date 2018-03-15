//q10035.cpp - 2011/09/06
//10035 - Primary Arithmetic
//accepted at 2011-09-07 09:51:09
//run time = 0.012
#include <stdio.h>
#include <cstring>
using namespace std;


int main(){
	while(true){
		//input
		char inputA[10] = {0};
		char inputB[10] = {0};
		scanf("%s %s",inputA ,inputB);
		if(inputA[0]=='0'&&inputB[0]=='0'&&strlen(inputA)==1&&strlen(inputB)==1){break;}
		int a[11] = {0}, b[11] = {0}, c[11] = {0};
		int totalCarry = 0;
		int maxLen = 0;

		maxLen = strlen(inputA);
		for(int i=0;i<maxLen;i++){
			a[maxLen-i-1] = inputA[i] -'0';
		}
		maxLen = strlen(inputB);
		for(int i=0;i<maxLen;i++){
			b[maxLen-i-1] = inputB[i] -'0';
		}

		//add
		int tempCarry = 0;
		for(int i=0;i<=10;i++){
			c[i] = a[i] + b[i] + tempCarry;
			printf("c[i] = a[i] + b[i] + tempCarry\nc[%d] = %d + %d + %d = %d\n",i,a[i],b[i], tempCarry,c[i]);
			if(tempCarry==1){tempCarry=0;}
			if(c[i]>=10){
				c[i] -= 10;
				tempCarry=1;
				totalCarry+=1;
			}
		}

		//output
		if(totalCarry==0){
			printf("No carry operation.\n");
		}else if(totalCarry==1){
			printf("1 carry operation.\n");
		}else if(totalCarry>1){
			printf("%d carry operations.\n", totalCarry);
		}

	}
	return 0;
}
