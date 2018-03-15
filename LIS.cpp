//LIS.cpp - 2012/01/04
//accepted at 
//run time = 
#include <stdio.h>
#define MAX_N 100
int n;
int a[MAX_N];
int dp[MAX_N];

int max(int A, int B){
	return A>B?A:B;
}
void solve(){
	int res = 0;
	for(int i=0; i<n; i++){
		dp[i] = 1;
		for(int j=0; j<i; j++)
			if(a[j] < a[i]){
				printf("when i = %d and j = %d\n%d < %d\n", i, j, a[j], a[i]);
				dp[i] = max(dp[i], dp[j] + 1);
			}
		res = max(res, dp[i]);
	}
	printf("%d\n", res);
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("LIS.in", "r", stdin);
	freopen("LIS.out", "w", stdout);
	#endif


	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	solve();
	return 0;
}
