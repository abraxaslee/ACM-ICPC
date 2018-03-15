//q11494.cpp - 2011/12/03
//accepted at 
//run time = 0.008
#include <stdio.h>

int Qx, Qy, Tx, Ty;

void solve(){

	if(Qx == Tx && Qy == Ty){
		puts("0");
		return;
	}

	if(Qx == Tx || Qy == Ty || Qx+Qy == Tx+Ty || Qx-Qy == Tx-Ty){
		puts("1");
		return;
	}

	puts("2");
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11494.in", "r", stdin);
	freopen("q11494.out", "w", stdout);
	#endif


	while(scanf("%d%d%d%d", &Qx, &Qy, &Tx, &Ty)!=EOF){
		if(Qx+Qy+Tx+Ty == 0)	break;
		solve();
	}
	return 0;
}
