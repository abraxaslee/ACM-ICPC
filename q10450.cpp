//q10450.cpp - 2011/11/19
//accepted at 
//run time = 0.004 c
#include <stdio.h>

long long int Fib[60];
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
	Fib[39] = 165580141;
	Fib[40] = 267914296;
	Fib[41] = 433494437;
	Fib[42] = 701408733;
	Fib[43] = 1134903170;
	Fib[44] = 1836311903;
	Fib[45] = 2971215073LL;
	Fib[46] = 4807526976LL;
	Fib[47] = 7778742049LL;
	Fib[48] = 12586269025LL;
	Fib[49] = 20365011074LL;
	Fib[50] = 32951280099LL;
	Fib[51] = 53316291173LL;
	Fib[52] = 86267571272LL;
	Fib[53] = 139583862445LL;
	Fib[54] = 225851433717LL;
	Fib[55] = 365435296162LL;
	Fib[56] = 591286729879LL;
	Fib[57] = 956722026041LL;
	Fib[58] = 1548008755920LL;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10450.in", "r", stdin);
	freopen("q10450.out", "w", stdout);
	#endif

	int currentCase = 0, caseNum, input; build_fib();
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d", &input);
		printf("Scenario #%d:\n%lld\n\n", ++currentCase, Fib[input]);
	}
	return 0;
}
