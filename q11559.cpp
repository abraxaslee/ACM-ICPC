//q11559.cpp - 2011/12/17
//accepted at 
//run time = 0.004
#include <stdio.h>
#define INT_MAX 2147483647

int min(int A, int B){
	return A<B?A:B;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11559.in", "r", stdin);
	freopen("q11559.out", "w", stdout);
	#endif

	int member, budget, hotel, weeks, tmp, fee, bestFee, i;
	while(scanf("%d%d%d%d", &member, &budget, &hotel, &weeks)!=EOF){
		bestFee = INT_MAX;
		while(hotel--){
			scanf("%d", &fee);
			for(i=0; i<weeks; ++i){
				scanf("%d", &tmp);
				if(member <= tmp)
					bestFee = min(bestFee, fee);
			}
		}

		if(bestFee == INT_MAX)
			puts("stay home");
		else{
			bestFee *= member;
			if(bestFee <= budget)
				printf("%d\n", bestFee);
			else
				puts("stay home");
		}
	}
	return 0;
}
