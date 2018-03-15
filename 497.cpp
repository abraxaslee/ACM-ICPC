//2012/02/13
//497.cpp
//Run time: 0.008

#include <stdio.h>
#include <stdlib.h>
char buff[100];
int a[1000], dp[1000], prev[1000];
int top, pos, once;

int LIS(){
	int ans, i, j;

	for(i=0; i<top; ++i)
		dp[i] = 1, prev[i] = -1;
	for(i=1; i<top; ++i)
		for(j=0; j<i; ++j)
			if(a[i] > a[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1, prev[i] = j;

	for(pos=ans=i=0; i<top; ++i)
		if(ans < dp[i])
			ans = dp[i], pos = i;

	/*printf("pos = %d\n", pos);
	for(i=0; i<top; ++i)
		printf("prev[%d] = %d\n", i, prev[i]);*/
	return ans;
}

void backtrack(int x){
	if(prev[x] != -1) backtrack(prev[x]);
	printf("%d\n", a[x]);
	return;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("497.in", "r", stdin);
	freopen("497.out", "w", stdout);
	#endif

	int caseNum, hits;
	scanf("%d", &caseNum); getchar(); getchar();

	while(caseNum--){
		top = 0;
		while( gets(buff) != NULL ){
			if(buff[0] == '\0') break;
			a[top++] = atoi(buff);
			//printf("[%d] %d\n", top-1, a[top-1]);
		}
		hits = LIS();
		if(once)
			putchar(10);
		printf("Max hits: %d\n", hits);
		if(hits)
			backtrack(pos);
		once = 1;

	}
	return 0;
}
