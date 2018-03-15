//q10106.cpp - 2011/11/25
//accepted at 
//run time = 0.004
//bignum production
#include <stdio.h>
#include <string.h>
#define CARRY 1000

int bigNum[2][100];
int top[2];
int resultTop;

char buffer[300];

int max(int A, int B){
	return A>B ? A:B;
}

void strToBignum(int target){
	int length = strlen(buffer);
	int leadingZero = (3 - (length%3))%3;

	char output[300] = {'\0'};
	if(leadingZero == 1){
		output[0] = '0'; output[1] = '\0';
	}else if(leadingZero == 2){
		output[0] = '0'; output[1] = '0';	output[2] = '\0';
	}

	strcat(output, buffer);

	length += leadingZero;
	top[target] = length/3;

	int i;
	for(i=top[target]-1;i>=0;--i)
		sscanf(output,"%3d%s", &bigNum[target][i], &output);

	//debug
	//for(i=top[target]-1;i>=0;--i)
	//	printf("%3d_", bigNum[target][i]);
	//putchar(10);
	//debug end
	return;
}

void bignum_product(){
	int i, j;
	int result[300] = {};
	//printf("DEBUG : top[0] = %d \t top[1] = %d\n", top[0], top[1]);

	for(i=0;i<top[0];++i)
		for(j=0;j<top[1];++j){
			result[i+j] += bigNum[0][i] * bigNum[1][j];
			//printf("DEBUG : [%d] = %d (+= %d * %d)\n", i+j, result[i+j], bigNum[0][i], bigNum[1][j]);
			if(result[i+j] > CARRY){
				result[i+j+1] += result[i+j] / CARRY;
				result[i+j] %= CARRY;
			}
		}

	resultTop = top[0] + top[1] -1;
	while(result[resultTop] > 0){
		if(result[resultTop] > CARRY){
			result[resultTop+1] = result[resultTop] / CARRY;
			result[resultTop] %= CARRY;
			}
		resultTop += 1;
	}

	while(result[resultTop] == 0 && resultTop > 0){
		resultTop -= 1;
	}
	//printf("DEBUG : resultTop = %d\n", resultTop);

	//printout

	printf("%d", result[resultTop]);
	for(i=resultTop-1;i>=0;--i)
		printf("%03d", result[i]);
	putchar(10);
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10106.in", "r", stdin);
	freopen("q10106.out", "w", stdout);
	#endif

	while(gets(buffer)!=NULL){
		strToBignum(0);
		gets(buffer);
		strToBignum(1);

		bignum_product();
	}
	return 0;
}
