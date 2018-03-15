//2012/01/17
//12416.cpp
//Run time: 0.012

#include <stdio.h>

int getMAX(int A, int B){
	return A>B?A:B;
}

int main(){
/*
	#ifndef ONLINE_JUDGE
	freopen("12416.in", "r", stdin);
	freopen("12416.out", "w", stdout);
	#endif*/

	int c, space, max, ans, carry;
	max = space = ans = 0;
	while((c = getchar()) != EOF){
		if(c == 10){
			max = getMAX(space,max);
			carry = 0;
			while(max > 1){
				if(max & 1){ if(carry) max++; carry ^= 1;}
				max >>= 1;
				ans++;
			}
			if(carry)
				ans++;
			printf("%d\n", ans);
			max = space = ans = 0;
		}
		else if(c == 32)
			space++;
		else{
			max = getMAX(space,max);
			space = 0;
		}
	}
	return 0;
}
