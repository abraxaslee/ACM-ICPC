//2012/02/17
//133.cpp
//Run time:

#include <stdio.h>
#include <string.h>
int N, K, M, k, m;

void solve(int top){

	while(top){
		K %= top;
		M %= top;
	}

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("133.in", "r", stdin);
	freopen("133.out", "w", stdout);
	#endif


    while(1){
    	scanf("%d%d%d", &N, &K, &M);
    	solve();
    }
	return 0;
}
