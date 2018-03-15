//q10161.cpp - 2011/12/27
//accepted at 
//run time = 0.004
#include <stdio.h>
#include <math.h>

int x, y, N,  iTmp, sq;
double dTmp;
void solve(){
	dTmp = sqrt(N);
	iTmp = (int)dTmp;
	if(iTmp == dTmp){
		if(iTmp % 2 == 0){
			x = iTmp;
			y = 1;
			return;
		}else{
			y = iTmp;
			x = 1;
			return;
		}
	}
	sq = iTmp*iTmp;
	sq += ++iTmp;

	if( sq == N){
		x = y = iTmp;
		return;
	}

	if( N > sq ){
		if(iTmp %2 == 0){
			x = iTmp; y = iTmp - (N - sq);
		}else{
			y = iTmp; x = iTmp - (N - sq);
		}
		return;
	}else{
		if(iTmp %2 == 0){
			y = iTmp; x = iTmp - (sq - N);
		}else{
			x = iTmp; y = iTmp - (sq - N);
		}
		return;
	}
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10161.in", "r", stdin);
	freopen("q10161.out", "w", stdout);
	#endif

	while(scanf("%d", &N)==1){
		if(N == 0)	break;
		solve();
		printf("%d %d\n", x, y);
	}
	return 0;
}
