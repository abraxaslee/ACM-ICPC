//q12208.cpp - 2011/10/21
//accepted at 
//run time = 
#include <stdio.h>

int countOnes(int inputNum){
	int result = 0;
	while(inputNum > 0){
		if(inputNum&1){
			result += 1;
		}
		inputNum = inputNum >> 1;
	}
	return result;
}

int showBinary(int inputNum){
	int result = 0;
	while(inputNum > 0){
		result *= 10;
		result += inputNum%2;
		inputNum /= 2;
	}
	return result;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q12208.in", "r", stdin);
	freopen("q12208.out", "w", stdout);
	#endif

	int a, b;
	while(scanf("%d%d", &a, &b)!=EOF && a+b > 0){
		for(int i=a;i<=b;i++){
			printf("%d\t=\t%08d (%d)\n", i, showBinary(i), countOnes(i));
		}
	}
	return 0;
}
