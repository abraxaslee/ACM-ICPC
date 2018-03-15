//2012/03/30
//10497.cpp
//Run time: 0.032

#include <stdio.h>
#define CARRY 1000000
int dp[801][350], top[801];

void build_table(){
	dp[0][0] = top[0] = top[1] = 1;
	dp[1][0] = 0;
	int i, z, limit, prev, last;
	for(z=2; z<801; ++z){
		last = z - 1, prev = z - 2;
		limit = top[last];

		for(i=0; i<limit; ++i){
			dp[z][i] += (dp[prev][i] + dp[last][i]) * last;
			if(dp[z][i] >= CARRY){
				dp[z][i+1] += dp[z][i] / CARRY;
				dp[z][i] %= CARRY;
			}
		}
		while(dp[z][i] > 0) ++i;
		top[z] = i;
	}
}

void print(int n){
	static int i;
	printf("%d", dp[n][top[n] - 1]);
	for(i=top[n] -2; i >= 0 ; --i)
		printf("%06d", dp[n][i]);
	putchar(10);
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10497.in", "r", stdin);
	freopen("10497.out", "w", stdout);
	#endif

	int input; build_table();
	while(scanf("%d", &input) == 1){
		if(input == -1) break;
		print(input);
	}
	return 0;
}
