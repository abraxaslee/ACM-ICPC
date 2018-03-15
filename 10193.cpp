//2012/03/30
//10193.cpp
//Run time: 0.004

#include <stdio.h>

int GCD(int x, int y){
	static int T;

	while (y != 0){
		T = x;
		x = y;
		y = T%y;
	}

	return x;
}



int main(){

	#ifndef ONLINE_JUDGE
	freopen("10193.in", "r", stdin);
	freopen("10193.out", "w", stdout);
	#endif

	int testCase, caseNum = 0;
	int S1, S2, i, c;

	scanf("%d", &testCase);	getchar();
	while(testCase--){
		S1 = S2 = 0;
		while(1){
			c = getchar();
			if(c == 10 || c == -1) break;
			S1 <<= 1;
			S1 += c - '0';
		}
		while(1){
			c = getchar();
			if(c == 10 || c == -1) break;
			S2 <<= 1;
			S2 += c - '0';
		}

		if(GCD(S1, S2) == 1)
			printf("Pair #%d: Love is not all you need!\n", ++caseNum);
		else
			printf("Pair #%d: All you need is love!\n", ++caseNum);
	}

	return 0;
}
