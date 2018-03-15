//q993.cpp - 2011/10/05
//accepted at 
//run time = 0.008
#include <stdio.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q993.in", "r", stdin);
	freopen("q993.out", "w", stdout);
	#endif

	int caseNum = 0, N;
	scanf("%d", &caseNum);
	while(caseNum-- >0){
		int stack[20] = {}, top = 0;
		scanf("%d", &N);

		if(N==1){
			printf("1\n");
			continue;
		}else if(N==0){
			printf("10\n");
			continue;
		}
		int i=9;
		while(N>1&&i>1){
			if( N%i == 0){
				//printf("\t%d%%%d = 0, put %d into stack\n", N, i, i);
				stack[top++] = i;
				N /= i;
			}else{
				i--;
			}
		}

		if(N==1){
				while(--top >= 0){
					printf("%d", stack[top]);
				}
				putchar(10);

			}else{
				printf("-1\n");
		}
	}
	return 0;
}
