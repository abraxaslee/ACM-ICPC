//q679v2.cpp - 2011/09/22
//accepted at 2011-09-22 16:56:05
//run time = 0.052
#include <stdio.h>
using namespace std;

int main(){
	int caseNum;
	int deep, ball, reball, base;
	scanf("%d", &caseNum);
	caseStart:
	scanf("%d %d", &deep, &ball);
	base = 1 << (deep - 1 );
	ball = (ball -1 ) % base;
	reball = 0;

	for(int i= 0;i<deep-1;i++){
		reball = reball << 1;
		if(ball&1){
			reball += 1;
		}
		ball = ball >> 1;
	}

	printf("%d\n", base + reball);
	if(--caseNum>0){
		goto caseStart;
	}
	return 0;
}
