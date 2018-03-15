//q11723.cpp - 2011/11/21
//accepted at 
//run time = 0.020
#include <stdio.h>

int binarySearch(int diff, int org){
	int low = 0, high = 26, mid, tmp;

	while(low <= high){
		mid = (low + high)/2;
		tmp = org * mid;

		if( tmp >= diff && org * (mid-1) < diff)
			return mid;
		else if( tmp < diff)
			low = mid + 1;
		else if( tmp > diff)
			high = mid - 1;
	}

	return -1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11723.in", "r", stdin);
	freopen("q11723.out", "w", stdout);
	#endif

	int road, number, currentCase = 0;
	while(scanf("%d%d", &road, &number)){
		if(road+number == 0)
			break;

		printf("Case %d: ", ++currentCase);
		if(road-number <= 0){
			puts("0");
			continue;
		}
		else if( road > (number + number*26)){
			puts("impossible");
			continue;
		}
		printf("%d\n", binarySearch(road-number,number));

	}

	return 0;
}
