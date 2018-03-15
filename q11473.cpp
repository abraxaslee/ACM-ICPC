//q11473.cpp - 2011/10/13
//accepted at 2011-10-13 02:03:06
//run time = 0.008
#include <stdio.h>
using namespace std;

int getDouble(int inputNum){
	inputNum -= 48;
	inputNum *= 2;
	while(inputNum >=10){
		int tmp = inputNum %10;
		inputNum = inputNum/10 + tmp;
	}
	return inputNum;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11473.in", "r", stdin);
	freopen("q11473.out", "w", stdout);
	#endif

	int caseNum, sum;
	char s[30] = {};
	scanf("%d\n", &caseNum);
	while(caseNum-- >0){
		sum = 0;
		gets(s);
		for(int i=0;i<=15;i+=5){
			sum += getDouble(s[i]) + getDouble(s[i+2]);
			sum += s[i+1] + s[i+3] - 96;
		}
		if(sum % 10 == 0){
			printf("Valid\n");
		}else{
			printf("Invalid\n");
		}
	}
	return 0;
}
