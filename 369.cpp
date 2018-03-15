//2012/02/23
//369.cpp
//Run time: 0.008

#include <stdio.h>

long long int solve(int n, int m){
	int i;
	long long int result = 1;
	m = n - m < m ? n - m : m;
	for(i=1; i<= m; ++i, --n){
		result *= n;
		result /= i;
	}

	return result;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("369.in", "r", stdin);
	freopen("369.out", "w", stdout);
	#endif

	int N, M;
	while(scanf("%d%d", &N, &M)==2){
		if(N + M == 0)	break;
		printf("%d things taken %d at a time is %lld exactly.\n", N, M, solve(N, M));
	}
	return 0;
}
