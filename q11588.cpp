//q11588.cpp - 2011/11/25
//accepted at 
//run time = 0.004
#include <stdio.h>

int max(int A, int B){
	return A>B? A:B;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11588.in", "r", stdin);
	freopen("q11588.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0, row, col, M, N, c, i, important, count;
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d%d%d%d", &row, &col, &M, &N);
		getchar();

		i=0, important = 0, count = 0;
		int words[100] = {};
		while( i < row){
			c = getchar();
			if(c ==10)
				i += 1;
			else
				words[c] += 1;
		}
		for(i=65;i<=90;++i)
			important = max(words[i], important);

		for(i=65;i<=90;++i)
			if(words[i] == important)
				count += words[i];

		printf("Case %d: %d\n", ++currentCase, M*count + (row*col-count)*N);
	}
	return 0;
}
