//2012/02/11
//231.cpp
//Run time: 0.004

#include <stdio.h>
#include <string.h>

int missile[70000];
int dp[70000];
int top, caseNum, i, j, ans, once;

int max(int a, int b){
	return a>b?a:b;
}

void solve(){

	memset(dp, 0, sizeof(int)* top +1);
	for(ans=i=0; i<top; ++i){
		dp[i] = 1;
		for(j=0; j<i; ++j)
			if(missile[i] <= missile[j])
				dp[i] = max(dp[i], dp[j]+1);
		ans = max(ans, dp[i]);
	}
	if(once)	putchar(10);
	printf("Test #%d:\n  maximum possible interceptions: %d\n", ++caseNum, ans);
	top = 0;
	once = 1;
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("231.in", "r", stdin);
	freopen("231.out", "w", stdout);
	#endif


	while(scanf("%d", &missile[top]) != EOF){
		if(missile[top] == -1){
			if(top == 0)	break;
			solve();
		}else
			++top;

	}
	return 0;
}
