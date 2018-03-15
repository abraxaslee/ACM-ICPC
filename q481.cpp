//q481.cpp - 2012/01/05
//accepted at 
//run time = 
#include <stdio.h>
#include <algorithm>
#define INF 2147483647
#define MAX_N 100000
using namespace std;

int array[MAX_N];
int dp[MAX_N];
int position[MAX_N];
int n;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q481.in", "r", stdin);
	freopen("q481.out", "w", stdout);
	#endif

	while(scanf("%d", &array[n])!=EOF)
		n++;

	fill(dp, dp+n, INF);
	fill(position, position+n, INF);
	int pos;
	for(int i=0; i < n ; ++i){
		pos = lower_bound(dp, dp+n, array[i]) - dp;
		if( position[pos] >  i){
			printf("position[%d] = %d <= i = %d\n", pos, position[pos], i);
			dp[pos] = array[i];
			position[pos] = i;
		}
	}
	int ans = lower_bound(dp, dp+n, INF) - dp;
	printf("%d\n", ans);
	for(int i=0; i < ans; ++i)
		printf("dp[%d] = %d from %d\n", i, dp[i], position[i]);
	return 0;
}
