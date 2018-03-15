//2012/03/26
//11827.cpp
//Run time: 0.004

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buff[50000];
int num[105];

int GCD(int x, int y){
	static int T;

	while(y != 0){
		T = x;
		x = y;
		y = T%y;
	}

	return x;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11827.in", "r", stdin);
	freopen("11827.out", "w", stdout);
	#endif


	int testCase, top, i, z, temp;
	int maxGCD;
	char *tok;
	scanf("%d", &testCase);	getchar();
	while(testCase--){
		gets(buff);
		top = 0;
		maxGCD = 1;
		for(tok = strtok(buff, " "); tok != NULL; tok = strtok(NULL, " "))
			num[top++] = atoi(tok);

		for(i=0; i<top; ++i)
			for(z=i+1; z<top; ++z){
				if(num[i] <= maxGCD || num[z] <= maxGCD)	continue;
				temp = GCD(num[i], num[z]);
				maxGCD = (maxGCD > temp) ? maxGCD : temp;
			}

		printf("%d\n", maxGCD);
	}
	return 0;
}
