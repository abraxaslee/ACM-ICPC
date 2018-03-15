//2012/04/03
//10679.cpp
//Run time: 2.380

#include <stdio.h>
char String[100005];
char Sub[1005];
int Fail[1005];

int kmp(){
	static int m, next, i, k, len;

	Fail[0] = k = -1;
	for (i = 1 ; Sub[i] != '\0'; ++i) {
		while(k >= 0 && Sub[i] != Sub[k+1])
			k = Fail[k];
		if(Sub[i] == Sub[k+1])
			++k;
		Fail[i] = k;
	}

	len = i - 1;

	for(i = 0, k = -1; String[i] != '\0'; ++i){
		while(k >= 0 && String[i] != Sub[k+1])
			k = Fail[k];
		if(String[i] == Sub[k+1]) ++k;

		if(k == len) return 1;
	}
	return 0;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10679.in", "r", stdin);
	freopen("10679.out", "w", stdout);
	#endif


	int testCase, Q;
	scanf("%d", &testCase); getchar();

	while(testCase--){
		gets(String);
		scanf("%d", &Q); getchar();
		while(Q--){
			gets(Sub);

			if(kmp())
				puts("y");
			else
				puts("n");

		}
	}
	return 0;
}
