//2012/03/22
//108.cpp
//Run time: 0.008

#include <stdio.h>
#define INF -2147483647

int sum[105][105];
int N;

int Kadane(int *array){
	static int i, max, sum;
	max = INF;
	for(sum=i=0; i<N; ++i){
		sum += array[i];
		if(sum < 0) sum = 0;
		else if(sum > max)	max = sum;
	}

	return max;
}

int KadaneM(int *array, int *up){
	static int i, max, sum;
	max = INF;
	for(sum=i=0; i<N; ++i){
		sum += (array[i] - up[i]);
		if(sum < 0) sum = 0;
		else if(sum > max)	max = sum;
	}
	return max;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("108.in", "r", stdin);
	freopen("108.out", "w", stdout);
	#endif

	int i, j, temp, MAX;
	int dp[105];
	while(scanf("%d", &N) == 1){

		for(j=0; j<N; ++j)
			scanf("%d", &sum[0][j]);
		MAX = Kadane(sum[0]);

		for(i=1; i<N; ++i){
			for(j=0; j<N; ++j){
				scanf("%d", &temp);
				sum[i][j] = temp + sum[i-1][j];
			}
			temp = Kadane(sum[i]);
			if(temp > MAX) MAX = temp;

			for(j=0; j<i; ++j){
				temp = KadaneM(sum[i], sum[j]);
				if(temp > MAX) MAX = temp;
			}
		}

		printf("%d\n", MAX);
	}

	return 0;
}
