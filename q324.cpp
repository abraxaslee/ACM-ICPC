//q324.cpp - 2011/11/25
//accepted at 
//run time = 0.020
#include <stdio.h>
#define CARRY 1000000
#define MAXDIGIT 800

int factorial[1001][MAXDIGIT];
int top[1001];
int digits[1001][10];

void setFactorial(int n){
	int i;

	for(i = 0 ; i < top[n-1] ; ++i){
		factorial[n][i] += factorial[n-1][i] * n;
		if(factorial[n][i] >= CARRY){
			factorial[n][i+1] += factorial[n][i] / CARRY;
			factorial[n][i] %= CARRY;
		}
	}


	while(factorial[n][i] > 0){
		i += 1;
	}
	top[n] = i;
	return;
}

void getFactorial(int n){
	int i;
	printf("%d!\n", n);

	printf("%d", factorial[n][top[n]-1]);
	for(i = top[n]-2 ;i >= 0 ; --i)
		printf("%06d", factorial[n][i]);

	putchar(10);

	return;
}

void build_Factorial(){
	int i;

	factorial[0][0] = 1;
	top[0] = 1;

	factorial[1][0] = 1;
	top[1] = 1;

	factorial[2][0] = 2;
	top[2] = 1;

	for(i = 3 ; i < 1001; ++i)
		setFactorial(i);

	return;
}

void getDigits(int n){
	int i, j, tmp;
	tmp = factorial[n][top[n]-1];
	while(tmp > 0){
		digits[n][tmp%10] += 1;
		tmp /= 10;
	}

	for(i=top[n]-2;i>=0;--i){
		tmp = factorial[n][i];
		for(j=0;j<6;j++){
			digits[n][tmp%10] += 1;
			tmp /= 10;
		}
	}
	return;
}

void build_Digits(){
	int i;
	for(i=0;i<367;++i)
		getDigits(i);
	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif

	build_Factorial();
	int n;
	build_Digits();
	while(scanf("%d", &n) != EOF){
		if(n==0) break;
		printf("%d! --\n", n);
		printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",digits[n][0], digits[n][1], digits[n][2], digits[n][3], digits[n][4], digits[n][5], digits[n][6], digits[n][7], digits[n][8], digits[n][9]);	}
	return 0;
}
