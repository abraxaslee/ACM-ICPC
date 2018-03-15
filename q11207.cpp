//q11207.cpp - 2011/12/11
//accepted at 
//run time = 0.012
#include <stdio.h>
#define INT_MIN -2147483647

double max(double numA, double numB){
	return numA>numB? numA:numB;
}

double min(double numA, double numB){
	return numA<numB? numA:numB;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11207.in", "r", stdin);
	freopen("q11207.out", "w", stdout);
	#endif

	int W, H, L, S, maxPaper, paper, i;
	double size, maxSize;
	while(scanf("%d", &paper)!=EOF){
			if(paper	 == 0) 	break;
			maxSize = INT_MIN;
			maxPaper = 1;
			for(i = 0; i < paper; ++i){
					scanf("%d%d", &W, &H);
					if(W > H){
						L = W;		S = H;
					}else{
						L = H;		S = W;
					}
					size = max(min(L/4.0, S), S/2.0);
					if(size > maxSize){
						maxPaper = i+1;
						maxSize = size;
					}
			}
			printf("%d\n", maxPaper);
	}
	return 0;
}
