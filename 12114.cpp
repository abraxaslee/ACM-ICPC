//2012/02/18
//12114.cpp
//Run time: 0.004

#include <stdio.h>

int current;

double min(double a, double b){
	return a<b?a:b;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("12114.in", "r", stdin);
	freopen("12114.out", "w", stdout);
	#endif

	int B, S;
	double before, after;
	while(1){
		scanf("%d%d", &B, &S);
		if(B + S == 0) break;
		if(B == 1){
			printf("Case %d: :-\\\n", ++current);
			continue;
		}
		before = min((double)S/B, 1.0);
		after = min(((double)S-1)/(B-1), 1.0);

		if(before == after)
			printf("Case %d: :-|\n", ++current);
		else if(before > after)
			printf("Case %d: :-(\n", ++current);
		else
			printf("Case %d: :-)\n", ++current);
	}
	return 0;
}
