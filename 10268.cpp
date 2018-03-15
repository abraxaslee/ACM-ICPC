//2012/01/11
//10268.cpp
//Run time: 0.100
//Algorithm: Horner's Rule
#include <stdio.h>
#include <string.h>

int c[1000005];
char buff[1000005];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10268.in", "r", stdin);
	freopen("10268.out", "w", stdout);
	#endif

	int n, i, ans, x, top;
	char *nxt;

	while(scanf("%d", &x)!=EOF){
		getchar();
		gets(buff);
		nxt = strtok(buff, " ");
		ans = n = 0;
		while(nxt != NULL){
			sscanf(nxt, "%d", &c[n++]);
			nxt = strtok(NULL, " ");
		}

		top = n-1;
		for(i=0; i<top; ++i){
			ans *= x;
			ans += c[i] * (top-i);
		}

		printf("%d\n", ans);
	}

	return 0;
}
