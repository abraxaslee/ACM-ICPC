//q1225.cpp - 2011/10/05
//accepted at 
//run time = 0.004(c)
#include <stdio.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q1225.in", "r", stdin);
	freopen("q1225.out", "w", stdout);
	#endif
	int caseNum = 0, N;
	scanf("%d", &caseNum);
	while(caseNum-- >0){
		int digits[10] = {};
		scanf("%d", &N);
		for(int i=1, buffer;i<=N;i++){
			buffer = i;
			while(buffer>0){
			digits[buffer%10] += 1;
			buffer /= 10;
			}
		}
		printf("%d %d %d %d %d %d %d %d %d %d\n", digits[0], digits[1], digits[2], digits[3], digits[4], digits[5], digits[6], digits[7], digits[8], digits[9]);
	}
	return 0;
}
