//2012/01/18
//11428.cpp
//Run time: 0.008

#include <stdio.h>

int cube[60];
int low, high, mid;

int binarySearch(int search){
    low = 0, high = 59;

	while(low <= high){
		mid = (low + high)/2;
		if(cube[mid] == search)
			return mid;
		else if(search > cube[mid])
			low = mid + 1;
		else if(search < cube[mid])
			high = mid - 1;
	}
	return -1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11428.in", "r", stdin);
	freopen("11428.out", "w", stdout);
	#endif

	int i, N, x, y, res, ans;
	for(i=1; i<60; ++i)
		cube[i] = i*i*i;

	while(scanf("%d", &N)!=EOF){
		if(N == 0)	break;

		for(ans=i=0; i<60; ++i){
			res = binarySearch( N + cube[i]);
			if(res >= 0 ){ x = res; y = i; ans = 1; break;}
		}

		if(ans)
			printf("%d %d\n", x, y);
		else
			puts("No solution");
	}
	return 0;
}
