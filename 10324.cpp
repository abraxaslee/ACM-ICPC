//2012/01/21
//10324.cpp
//Run time: 0.028
#include <stdio.h>

char buff[1000005];
int dp[1000005];
int current;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10324.in", "r", stdin);
	freopen("10324.out", "w", stdout);
	#endif

	int i, query, j, k, front, back, top;
	while(gets(buff)!=NULL){
		if(buff[0] == '\0')	break;
		dp[0] = (buff[0] == '1');

		for(i=1; buff[i] !='\0'; ++i)
			dp[i] = dp[i-1] + (buff[i] == '1');
		top = i;
		scanf("%d", &query);
		printf("Case %d:\n",++current);
		while(query--){
			scanf("%d%d", &i, &j);

			if(i>j){ back = i; front = j;}
			else { front = i; back = j;}

			if(back < top){
				if(buff[front] == '0' & buff[back] == '0' & dp[back]-dp[front] == 0)
					puts("Yes");
				else if(buff[front] == '1' & buff[back] == '1' & (dp[back]-dp[front] == back-front))
					puts("Yes");
				else
					puts("No");
			}else
				puts("No");
		}
		getchar();

	}


}
