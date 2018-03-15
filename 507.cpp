//2012/03/25
//507.cpp
//Run time: 0.112

#include <stdio.h>
#define INF -2147483640

int main(){

	#ifndef ONLINE_JUDGE
	freopen("507.in", "r", stdin);
	freopen("507.out", "w", stdout);
	#endif

	int Route, Stop, i, cstart, mstart, mend, max, sum;
	int temp, caseNum = 0;
	scanf("%d", &Route);
	while(Route--){
		scanf("%d", &Stop);

		--Stop;
		max = INF;

		for(i = sum = cstart = mstart = mend = 0; i<Stop; ++i){
			scanf("%d", &temp);
			sum += temp;
			if(sum < 0)
				cstart = i + 1, sum = 0;
			else if(sum > max)
				max = sum, mend = i, mstart = cstart;
			else if(sum == max && (i - cstart) > (mend - mstart))
				mend = i, mstart = cstart;

		}

		if(max == INF)
			printf("Route %d has no nice parts\n", ++caseNum);
		else
			printf("The nicest part of route %d is between stops %d and %d\n", ++caseNum, mstart +1, mend +2);

	}


	return 0;
}
