//q10931.cpp - 2011/12/11
//accepted at 
//run time = 0.012
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10931.in", "r", stdin);
	freopen("q10931.out", "w", stdout);
	#endif

	int TEN;
	int TWO[35];
	int top, parity, i;

	while(scanf("%d", &TEN)!=EOF){
		if(TEN == 0)		break;
		top = parity = 0;
		while(TEN > 0){
			TWO[top] = TEN %2;
			parity += TWO[top++];
			TEN /= 2;
		}
		printf("The parity of ");
		for(i=top-1; i>=0; --i)
			printf("%d", TWO[i]);
		printf(" is %d (mod 2).\n", parity);
	}

	return 0;
}
