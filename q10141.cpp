//q10141.cpp - 2011/11/26
//accepted at 
//run time = 0.008
#include <stdio.h>
#include <string.h>
char WTF[100];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10141.in", "r", stdin);
	freopen("q10141.out", "w", stdout);
	#endif

	int req, proposal, correct, bestCorrect, i, currentCase = 0;
	double bid, bestBid;
	char bestOne[1000], tmpOne[1000];
	bool once = false;

	while(scanf("%d%d", &req, &proposal)!=EOF){
		if(req + proposal == 0)	break;
		getchar();

		while(req--)
			gets(WTF);

		bestBid = -1, bestCorrect = -1;
		while(proposal--){
			gets(tmpOne);
			scanf("%lf %d", &bid, &correct);

			if(correct > bestCorrect){
				bestCorrect = correct;
				bestBid = bid;
				strcpy(bestOne, tmpOne);
			}else if(correct == bestCorrect && bid < bestBid){
				bestBid = bid;
				strcpy(bestOne, tmpOne);
			}

			getchar();
			while(correct--)
				gets(WTF);

		}

		if(once) putchar(10);
		printf("RFP #%d\n", ++currentCase);
		puts(bestOne);
		once = true;
	}
	return 0;
}
