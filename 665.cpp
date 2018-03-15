//2012/03/11
//665.cpp
//Run time: 0.008

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coins[105];
char buff[10000];
char sign[10];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("665.in", "r", stdin);
	freopen("665.out", "w", stdout);
	#endif

	int testCase, N, cmp, i, valid, suspect;
	int once = 0;
	char *token;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d%d", &N, &cmp);	getchar();
		memset(coins, 0, sizeof(int) * (N+2));
		while(cmp--){
			gets(buff);
			gets(sign);
			if(sign[0] == '='){
				token = strtok(buff, " ");
				for(token = strtok(NULL, " "); token != NULL; token = strtok(NULL, " "))
					coins[(atoi(token))] = 1;
			}
		}
		suspect = valid = 0;
		for(i = 1; i <= N; ++i)
			if(coins[i] == 0)	suspect = i, ++valid;

		if(once)	putchar(10);

		if(valid == 1 && suspect > 0)
			printf("%d\n", suspect);
		else
			puts("0");

		once = 1;
	}
	return 0;
}
