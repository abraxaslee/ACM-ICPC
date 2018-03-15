//q11332.cpp - 2011/10/05
//accepted at 
//run time = 0.008
#include <stdio.h>

inline int sum(int inputNum){
	if(inputNum<10){
		return inputNum;
	}
	int outputNum = 0;
	while(inputNum>0){
		outputNum += inputNum%10;
		inputNum /= 10;
	}
	return sum(outputNum);
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11332.in", "r", stdin);
	freopen("q11332.out", "w", stdout);
	#endif
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0){
			return 0;
		}else{
			printf("%d\n", sum(n));
		}
	}
	return 0;
}
