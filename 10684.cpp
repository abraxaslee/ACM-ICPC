//2012/03/26
//10684.cpp
//Run time: 0.072

#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10684.in", "r", stdin);
	freopen("10684.out", "w", stdout);
	#endif

	int sum, maxSum, top, temp;

	while(scanf("%d", &top) == 1){
		if(top == 0)	break;
		 maxSum = sum = 0;
		while(top--){
			scanf("%d", &temp);
			sum += temp;
			if(sum < 0)	sum = 0;
			else if(sum > maxSum) maxSum = sum;
		}
		if(maxSum == 0)
			puts("Losing streak.");
		else
			printf("The maximum winning streak is %d.\n", maxSum);
	}

	return 0;
}
