//q11340.cpp - 2011/10/15
//accepted at 
//run time = 0.096 / 0.092 c
#include <stdio.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11340.in", "r", stdin);
	freopen("q11340.out", "w", stdout);
	#endif

	int caseNum, lineNum;
	scanf("%d", &caseNum);
	while(caseNum-- >0){

		scanf("%d", &lineNum);
		getchar();

		int fee[128] = {}, tmp;
		int c;
		while(lineNum-- >0){
			c = getchar();
			scanf("%d\n", &tmp);
			fee[c] = tmp;
		}

		scanf("%d", &lineNum);
		getchar();

		long int payment = 0;
		while(lineNum > 0){
			c = getchar();
			payment += fee[c];
			if(c==10||c==-1){
				lineNum -= 1;
			}
		}

		printf("%ld.%02ld$\n", payment/100, payment%100);
	}
	return 0;
}
