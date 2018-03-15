//2012/03/18
//10131.cpp
//Run time: 0.012

#include <stdio.h>

int W[1005], S[1005], dp[1005], prev[1005];
int order[1005];

void quicksort( int start, int end )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; ++i )
            if( S[order[i]] > S[order[start]] )
            {
                ++piv;

                temp = order[i];
                order[i] = order[piv];
                order[piv] = temp;
            }

        temp = order[start];
        order[start] = order[piv];
        order[piv] = temp;

        quicksort( start, piv );
        quicksort( piv+1, end );
    }
}


void backtrack(int x){

	int i, top = 0;
	while(prev[x] != -1){
		dp[top++] = x;
		x = prev[x];
	}
	dp[top++] = x;
	for(i=top-1; i>=0; --i)
		printf("%d\n", order[dp[i]]+1);
	return;
}

void LIS(int top){
	int i, j, ans, pos;

	for(ans=i=0; i<top; ++i){
		dp[i] = 1;
		for(j=0; j<i; ++j)
			if(W[order[i]] > W[order[j]])
				if(dp[i] < dp[j] +1)
					dp[i] = dp[j] + 1, prev[i] = j;

		if(dp[i] > ans) ans = dp[i], pos = i;
	}
	printf("%d\n", ans);
	backtrack(pos);
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10131.in", "r", stdin);
	freopen("10131.out", "w", stdout);
	#endif

	int i = 0;
	while(scanf("%d%d", &W[i], &S[i]) == 2){
		order[i] = i;
		dp[i] = 1;
		prev[i] = -1;
		++i;
	}
	quicksort(0, i);
	LIS(i);
	return 0;
}
