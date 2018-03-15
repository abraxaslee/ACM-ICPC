//q11385.cpp - 2011/11/02
//accepted at 
//run time = 0.008
#include <stdio.h>

unsigned int Fib[47];
void buildFibTable(){
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
	Fib[45] = 2971215073U;
}
int BinarySearch(unsigned int search, unsigned int data[]){
		int low, high, mid;
		low = 0, high = 46;

		while(low <= high){
			mid = (low + high)/2;
			if(data[mid] == search)
				return mid;
			else if(search > data[mid])
				low = mid + 1;
			else if(data[mid] > search)
				high = mid - 1;
		}

		return -1;
}
int max(int a, int b){
	return a>b? a: b;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11385.in", "r", stdin);
	freopen("q11385.out", "w", stdout);
	#endif

	int caseNum, PassTop, i, z, tmp, last;
	unsigned int password[100];
	char encode[105];
	buildFibTable();

	scanf("%d", &caseNum);
	while(caseNum--){
		int appear[50] = {};
		char decode[105] = {};
		last = 0, tmp = 0;

		scanf("%d", &PassTop);
		for(i=0; i<PassTop; ++i)
			scanf("%u", &password[i]);

		getchar();
		gets(encode);
		for(i=0, z=0; z < PassTop && encode[i] != '\0'; ++i)
			if(encode[i] >= 65 && encode[i] <= 90){
				tmp = BinarySearch(password[z++], Fib);
				if(tmp < 0)		continue;
				decode[tmp] = encode[i];
				appear[tmp] = 1;
				last = max(tmp, last);
			}

		for(i=0; i<last; ++i)
			if(!appear[i])
				decode[i] = ' ';
		decode[last+1] = '\0';
		puts(decode);
	}
	return 0;
}
