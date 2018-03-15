//q10018.cpp - 2011/09/14
//Q10018 - Reverse and Add
//accepted at 2011-09-14 16:21:14
//run time = 0.012
#include <stdio.h>
using namespace std;

unsigned long int reverse(unsigned long int);

int main(){
	int caseNum = 0;
	scanf("%d", &caseNum);
	mainStart:
		unsigned long int iNum = 0;
		scanf("%lu",&iNum);
		int addCount = 0;
		do{
		iNum += reverse(iNum);
		addCount += 1;
		}while(!(iNum==reverse(iNum)));
		printf("%d %lu\n", addCount ,iNum);
		caseNum-=1;
		if(caseNum==0){return 0;}
	goto mainStart;
	return 0;
}

unsigned long int reverse(unsigned long int rNum){
	unsigned long int res = 0;
	rStart:
		if(rNum==0){return res;}
		res = (res*10) + (rNum %10);
		rNum /= 10;
	goto rStart;
	return res;
}
