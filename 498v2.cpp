//2012/01/11
//498v2.cpp
//Run time: 0.256
//Algorithm: Horner's Rule
#include <stdio.h>
#include <string.h>
long long int c[1005];
char buff[100000];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("498.in", "r", stdin);
	freopen("498.out", "w", stdout);
	#endif

	int n, i;
	long long int ans, x;
	char *nxt;

	while(gets(buff)!=NULL){
		n = 0;
		nxt = strtok(buff, " ");
		while(nxt != NULL){
			sscanf(nxt, "%lld", &c[n++]);
			nxt = strtok(NULL, " ");
		}

		gets(buff);
		nxt = strtok(buff, " ");
		if(nxt != NULL){
			sscanf(nxt, "%lld", &x);
			for(ans=i=0; i<n; i++){
				ans *= x;
				ans += c[i];
			}
			printf("%lld", ans);
		}
		nxt = strtok(NULL, " ");
		while(nxt != NULL){
			sscanf(nxt, "%lld", &x);
			for(ans=i=0; i<n; i++){
				ans *= x;
				ans += c[i];
			}
			printf(" %lld", ans);
			nxt = strtok(NULL, " ");
		}
		putchar(10);

	}


	return 0;
}
