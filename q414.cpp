//q414.cpp - 2011/10/16
//accepted at 
//run time = 0.004 c
#include <stdio.h>
using namespace std;

int min(int inputA ,int inputB){
	if(inputA < inputB){
		return inputA;
	}
	return inputB;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q414.in", "r", stdin);
	freopen("q414.out", "w", stdout);
	#endif

	int lineNum, c;
	while(scanf("%d", &lineNum)!=EOF && lineNum > 0){
		getchar();

		int space[13] = {}, i = 0, minNum = 99, totalLine = lineNum;
		while(lineNum > 0){

			c = getchar();

			if(c == 32){
				space[i] += 1;
			}else if(c == 10){
				minNum = min( minNum , space[i] );
				printf("[%d] %d spaces\n", i, space[i]);
				i++;
				lineNum--;
			}

		}
		printf("minNum = %d\n", minNum);
		int totalVoid = 0;
		for(int i=0;i<totalLine;i++){
			totalVoid += space[i] - minNum;
		}
		printf("%d\n", totalVoid);
	}
	return 0;
}
