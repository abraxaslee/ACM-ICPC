//q11584.cpp - 2011/11/22
//accepted at 
//run time = 
#include <stdio.h>

int main(){
	/*
	#ifndef ONLINE_JUDGE
	freopen("q11584.in", "r", stdin);
	freopen("q11584.out", "w", stdout);
	#endif*/

	int A, B, C;

	while(scanf("%d%d%d", &A, &B, &C)){

		if(A + B + C == 0)
			break;

		A *= A, B *= B, C *= C;

		if(A + B == C || B + C == A || A + C == B)
			puts("right");
		else
			puts("wrong");

	}
	return 0;
}
