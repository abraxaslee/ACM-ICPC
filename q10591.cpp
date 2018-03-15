//q10591.cpp - 2011/11/19
//accepted at 
//run time = 0.024 / 0.016c
#include <stdio.h>
#define MSIZE 800

bool unhappy[MSIZE];
bool happy[MSIZE];
int get[MSIZE];

int max(int A, int B){
	return A>B ? A:B;
}

int getS(int S0){
	if(S0 < MSIZE)
		if(get[S0] != 0)
			return get[S0];

	int S1 = 0, S = S0, lastDigit;
	while(S > 0){
		lastDigit = S % 10;
		S1 += lastDigit * lastDigit;
		S /= 10;
	}

	if(S0 < MSIZE)
		get[S0] = S1;

	return S1;
}

bool isHappy(int n){
	int S1 = getS(n);
	bool mem[MSIZE] = {};
	int stack[MSIZE] = {}, stacktop = 1, i;

	while(true){

		if( unhappy[S1] || mem[S1] )
			break;

		mem[S1] = true;
		stack[stacktop++] = S1;

		if( happy[S1] || S1 == 1 ){
			for(i=0;i<stacktop;++i)
				happy[stack[i]] = true;
			return true;
		}

		S1 = getS(S1);
	}

	for(i=0;i<stacktop;++i)
		unhappy[stack[i]] = true;

	return false;
}

void blacklist(){
	unhappy[2] = true; unhappy[4] = true;
	happy[7] = true; happy[49] = true;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10591.in", "r", stdin);
	freopen("q10591.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0, input; 	blacklist();
	scanf("%d", &caseNum);

	while(caseNum--){
		scanf("%d", &input);

		if(isHappy(input))
			printf("Case #%d: %d is a Happy number.\n", ++currentCase, input);
		else
			printf("Case #%d: %d is an Unhappy number.\n", ++currentCase, input);

	}
	return 0;
}
