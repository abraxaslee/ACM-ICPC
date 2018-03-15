//q424.cpp - 2011/10/29
//accepted at 
//run time = 0.004 c
#include <stdio.h>

int BigInt[155] = {};
int top;

int temp[200] = {};
int last;
char VeryLongInt[155];

int max(int A, int B){
	return ( A > B ) ? A : B;
}

void BigTmp(void){
	int i;
	for(i=0;VeryLongInt[i]!='\0';++i)
		temp[i] = VeryLongInt[i] - 48;

	last = i-1;
	return;
}

void BigAdd(void){
	int carry = 0, i;
	for(i=0; last >= 0; --last, ++i){

		if(carry == 1){
			BigInt[i] += temp[last] + 1;
			carry = 0;
		}else{
			BigInt[i] += temp[last];
		}

		if(BigInt[i] >= 10){
			BigInt[i] -= 10;
			carry = 1;
		}
	}

	while(carry == 1){
		BigInt[i] += 1;
		carry = 0;
		if(BigInt[i] >= 10){
			BigInt[i] -= 10;
			i++;
			carry = 1;
		}
	}

	top = max(top, i);
	return;
}
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q424.in", "r", stdin);
	freopen("q424.out", "w", stdout);
	#endif

	top = 0;
	int i;
	while(gets(VeryLongInt)!= NULL){
		if(VeryLongInt[0] == '0' && VeryLongInt[1] == '\0')
			break;
		BigTmp();
		BigAdd();
	}

	while(BigInt[top] == 0)
		--top;
	for(i=top;i>=0;--i)
		putchar(BigInt[i]+48);

	putchar(10);
	return 0;
}
