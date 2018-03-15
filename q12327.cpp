//q12327.cpp - 2011/10/24
//accepted at 
//run time = 
#include <stdio.h>
#include <string.h>

int card[13000];
int count[505];

void backtrack(int n, int m, int total){
	printf("n %d, m %d, total %d\n", n , m, total);

	if(n==m){
		count[total]++;
		printf("count[%d]++\n", total);
		return;
	}

	total += card[n];

	for(int i=n+1;i<=m;i++){
		backtrack(i, m, total);
	}
	return;
}
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q12327.in", "r", stdin);
	freopen("q12327.out", "w", stdout);
	#endif

	int caseNum, m, p;
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d%d", &m, &p);
		memset(count, 0, sizeof(count));
		for(int i=0;i<m;i++){
			scanf("%d", &card[i]);
		}

		backtrack(0 , m, 0);

		for(int i=0;i<505;i++)
			if(count[i] >0)
				printf("%d: %d\n", i, count[i]);
		putchar(10);
	}
	return 0;
}
