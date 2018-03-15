//2012/01/18
//111.cpp
//Run time: 0.008

#include <stdio.h>

int answer[21];
int bnswer[21];
int top;

int max(int A, int B){
	return A>B?A:B;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("111.in", "r", stdin);
	freopen("111.out", "w", stdout);
	#endif

	int i, j, tmp, ans;
	scanf("%d", &top);
	top++;
	for(i = 1; i < top; ++i)
		scanf("%d", &answer[i]);

	while(1){
		for(i = 1; i < top; ++i){
			if(scanf("%d", &tmp)==EOF) return 0;
			bnswer[tmp] = i;
		}

		int dp[21] = {};
		ans = 0;
		for(i = 1; i < top; ++i){
			dp[i] = 1;
			for(j = 1 ; j < i; ++j)
				if(answer[bnswer[j]] < answer[bnswer[i]])
					dp[i] = max(dp[i], dp[j]+1);
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
