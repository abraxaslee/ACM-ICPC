//q305.cpp - 2011/10/04
//accepted at 
//run time = 0.004
#include <stdio.h>
using namespace std;

inline int solve(int k){
	int pointed, alive, m, total;

	for(total = 2*k, m =k+1;alive!=k;m++){
		for(pointed = 0,alive = total;alive>k;alive--){
			if((pointed = (pointed + m - 1 )%alive)<k){
				break;
			}
		}
	}
	return m-1;
}

int main(){
	int k;
	while(scanf("%d", &k)&&k>0){
		printf("%d\n", solve(k));
	}
	return 0;
}
