//run time = 0.076
#include <stdio.h>
using namespace std;

int reverseBits(int inputNum, int times){
	int outputNum = 0;
	for(int i= 0;i<times;i++){
		outputNum = outputNum << 1;
		if(inputNum&1){
			outputNum += 1;
		}
		inputNum = inputNum >> 1;
	}
	return outputNum;
}

int main(){
	int caseNum;
	int deep, ball, base;

	scanf("%d %d", &deep, &ball);
	base = 1 << (deep - 1 );
	ball = (ball -1 ) % base;
	printf("%d\n", base + reverseBits(ball,deep-1));
	return 0;
}
