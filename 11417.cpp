//2012/03/31
//11417.cpp
//Run time: 0.004 (pre calculation)
#include <stdio.h>

int dp[501][501];

int GCD(int X, int Y){
	static int T, A, B;
	if(dp[X][Y]) return dp[X][Y];

	A = X, B = Y;
	while(B != 0){
		T = A;
		A = B;
		B = T%A;
	}
	return dp[X][Y] = dp[Y][X] = A;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("11417.in", "r", stdin);
	freopen("11417.out", "w", stdout);
	#endif

	int N = 2, i, j, ans;
	while(N < 501){
		ans = 0;
		for(i=1; i<N; ++i)
			for(j=i+1; j<=N; ++j)
				ans += GCD(i, j);

		printf("N[%d] = %d;\n", N, ans);
		++N;
	}

	return 0;
}
