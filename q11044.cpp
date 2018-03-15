//q11044.cpp - 2011/12/17
//accepted at 
//run time = 0.008
#include <stdio.h>

int getceil(double x){
	if(x == (int)x)
		return x;
	return (int)x+1;
}

int main(){
	/*
	#ifndef ONLINE_JUDGE
	freopen("q11044.in", "r", stdin);
	freopen("q11044.out", "w", stdout);
	#endif*/

	int caseNum, row, col;
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d%d", &row, &col);
		printf("%d\n", getceil((row-2)/3.0)*getceil((col-2)/3.0));
	}
	return 0;
}
