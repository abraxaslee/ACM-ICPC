//q846.cpp - 2011/11/12
//accepted at 
//run time = 0.004 c
#include <stdio.h>
#include <math.h>

double abs(double x, double y){
	return (x>y)? x-y : y-x;
}

int solve(int x, int y){
	double dDiff = sqrt(abs(x,y));
	int iDiff = (int) dDiff;

	if( dDiff - iDiff > 0.5){
		return (iDiff*2)+1;
	}else if( dDiff - iDiff == 0){
		return (iDiff*2)-1;
	}
	return iDiff*2;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q846.in", "r", stdin);
	freopen("q846.out", "w", stdout);
	#endif

	int x, y, caseNum;
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d %d", &x, &y);
		if( x - y == 0)
			puts("0");
		else
			printf("%d\n", solve(x,y));
	}
	return 0;
}
