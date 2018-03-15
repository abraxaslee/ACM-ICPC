//2012/03/05
//530.cpp
//Run time:

#include <stdio.h>

long long int solve(long long int n, long long int m){
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
	freopen("530.in", "r", stdin);
	freopen("530.out", "w", stdout);
	#endif

	long long int N, M;
	while(scanf("%lld%lld", &N, &M)==2){
		if(N + M == 0)	break;
		printf("%lld\n", solve(N, M));
	}
	return 0;
}
