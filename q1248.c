// 0.092
#include <stdio.h>
#include <string.h>
#define INT_MAX 2147483647
int N, caseNum;
int dp[1005][105];
int isfind[1005][105];
int material[1005][3];

int max(int inputA, int inputB){
	return (inputA>inputB)? inputA : inputB;
}

int min(int inputA, int inputB){
	return (inputA<inputB)? inputA : inputB;
}

int DP(int n, int m){
	if(n == N+1){ return 0;}
	if(isfind[n][m]==1){ return dp[n][m]; }
	dp[n][m] = INT_MAX;
	int i;
	for( i = max( 0, material[n][2] - m ); i <= material[n][1]; i++){
		int temp = DP( n+1, min(i, i + m - material[n][2]));
		if(temp == INT_MAX){
			continue;
		}
		dp[n][m] = min(dp[n][m], temp + i * material[n][0]);
	}
	isfind[n][m] = 1;
	return dp[n][m];
}
int main(void){

	scanf("%d", &caseNum);

	while(caseNum-- >0){

		int i;
		memset(isfind, 0, sizeof(isfind));
		scanf("%d", &N);
		for(i = 1; i <= N; i++){
			scanf("%d%d%d", &material[i][0], &material[i][1], &material[i][2]);
			material[i-1][1] = min(material[i-1][1] , material[i-1][2] + material[i][2]);
		}

		printf("%d\n", DP(1, 0));
	}
	return 0;
}
