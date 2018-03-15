//q948.cpp - 2011/11/15
//accepted at 
//run time = 0.004
#include <stdio.h>

int Fib[40];

void build_fib(){
	Fib[0] = 1;
	Fib[1] = 2;
	Fib[2] = 3;
	Fib[3] = 5;
	Fib[4] = 8;
	Fib[5] = 13;
	Fib[6] = 21;
	Fib[7] = 34;
	Fib[8] = 55;
	Fib[9] = 89;
	Fib[10] = 144;
	Fib[11] = 233;
	Fib[12] = 377;
	Fib[13] = 610;
	Fib[14] = 987;
	Fib[15] = 1597;
	Fib[16] = 2584;
	Fib[17] = 4181;
	Fib[18] = 6765;
	Fib[19] = 10946;
	Fib[20] = 17711;
	Fib[21] = 28657;
	Fib[22] = 46368;
	Fib[23] = 75025;
	Fib[24] = 121393;
	Fib[25] = 196418;
	Fib[26] = 317811;
	Fib[27] = 514229;
	Fib[28] = 832040;
	Fib[29] = 1346269;
	Fib[30] = 2178309;
	Fib[31] = 3524578;
	Fib[32] = 5702887;
	Fib[33] = 9227465;
	Fib[34] = 14930352;
	Fib[35] = 24157817;
	Fib[36] = 39088169;
	Fib[37] = 63245986;
	Fib[38] = 102334155;
	return;
}

void solve(int X){
	if( X == 0 ){
		puts("0 = 0 (fib)");
		return;
	}
	int i=38;
	printf("%d = ", X);
	while(i>=0){
		if( X >= Fib[i] ){
			X -= Fib[i];
			putchar(49);
			--i;
			break;
		}
		--i;
	}

	while(i>=0){
		if ( X >= Fib[i] ){
			X -= Fib[i];
			putchar(49);
		}else{
			putchar(48);
		}
		--i;
	}
	puts(" (fib)");
	return;
}


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q948.in", "r", stdin);
	freopen("q948.out", "w", stdout);
	#endif

	int caseNum, input; build_fib();
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d", &input);
		solve(input);
	}
	return 0;
}
