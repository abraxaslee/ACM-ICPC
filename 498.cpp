//2012/01/11
//498.cpp
//Run-time: 0.576
#include <stdio.h>
#include <string.h>
long long int c[1005];
char buff[100000];

long long int power(long long int num, int index){
	if(index == 0)
		return 1;
	if(index == 1)
		return num;
	long long int tmp = power(num, index/2);
	if(index & 1)
		return tmp*tmp*num;
	return tmp*tmp;
}

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
				if(c[i] == 0) continue;
				ans += c[i] * power(x, n-i-1);
			}
			printf("%lld", ans);
		}
		nxt = strtok(NULL, " ");
		while(nxt != NULL){
			sscanf(nxt, "%lld", &x);
			for(ans=i=0; i<n; i++){
				if(c[i] == 0) continue;
				ans += c[i] * power(x, n-i-1);
			}
			printf(" %lld", ans);
			nxt = strtok(NULL, " ");
		}
		putchar(10);

	}


	return 0;
}
