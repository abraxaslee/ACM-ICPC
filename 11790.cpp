//2012/03/08
//11790.cpp
//Run time: 0.096

#include <stdio.h>
#include <string.h>
int h[10005], w[10005], dp[10005];
int N, caseNum;

int max(int x, int y){
	return x > y ? x : y;
}

int LIS(){
	static int i, j, ans;
	for(ans=i=0; i<N; ++i){
		dp[i] = w[i];

		for(j=0; j<i; ++j)
			if(h[i] > h[j])
				dp[i] = max(dp[i], dp[j] + w[i]);

		ans = max(ans, dp[i]);
	}
	return ans;
}

int LDS(){
	static int i, j, ans;
	for(ans=i=0; i<N; ++i){
		dp[i] = w[i];

		for(j=0; j<i; ++j)
			if(h[i] < h[j])
				dp[i] = max(dp[i], dp[j] + w[i]);

		ans = max(ans, dp[i]);
	}
	return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11790.in", "r", stdin);
	freopen("11790.out", "w", stdout);
	#endif

	int testCase, i, increase, decrease;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d", &N);

		for(i=0; i<N; ++i)
			scanf("%d", &h[i]);

		for(i=0; i<N; ++i)
			scanf("%d", &w[i]);

		increase = LIS(), decrease = LDS();

		if(increase >= decrease)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", ++caseNum, increase, decrease);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", ++caseNum, decrease, increase);
	}
	return 0;
}
