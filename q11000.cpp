//q11000.cpp - 2011/11/17
//accepted at 
//run time = 0.004 c
#include <stdio.h>

unsigned int Fib[50];

void build_fib(){
	Fib[0] = 0;
	Fib[1] = 1;
	Fib[2] = 1;
	Fib[3] = 2;
	Fib[4] = 3;
	Fib[5] = 5;
	Fib[6] = 8;
	Fib[7] = 13;
	Fib[8] = 21;
	Fib[9] = 34;
	Fib[10] = 55;
	Fib[11] = 89;
	Fib[12] = 144;
	Fib[13] = 233;
	Fib[14] = 377;
	Fib[15] = 610;
	Fib[16] = 987;
	Fib[17] = 1597;
	Fib[18] = 2584;
	Fib[19] = 4181;
	Fib[20] = 6765;
	Fib[21] = 10946;
	Fib[22] = 17711;
	Fib[23] = 28657;
	Fib[24] = 46368;
	Fib[25] = 75025;
	Fib[26] = 121393;
	Fib[27] = 196418;
	Fib[28] = 317811;
	Fib[29] = 514229;
	Fib[30] = 832040;
	Fib[31] = 1346269;
	Fib[32] = 2178309;
	Fib[33] = 3524578;
	Fib[34] = 5702887;
	Fib[35] = 9227465;
	Fib[36] = 14930352;
	Fib[37] = 24157817;
	Fib[38] = 39088169;
	Fib[39] = 63245986;
	Fib[40] = 102334155;
	Fib[41] = 165580141;
	Fib[42] = 267914296;
	Fib[43] = 433494437;
	Fib[44] = 701408733;
	Fib[45] = 1134903170;
	Fib[46] = 1836311903;
	Fib[47] = 2971215073U;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11000.in", "r", stdin);
	freopen("q11000.out", "w", stdout);
	#endif

	int year; build_fib();
	while(scanf("%d", &year)!=EOF && year >= 0){
		printf("%u %u\n", Fib[year+2]-1, Fib[year+3]-1);
	}
	return 0;
}
