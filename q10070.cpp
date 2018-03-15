//q10070.cpp - 2011/11/20
//accepted at 
//run time = 0.284
#include <stdio.h>
#include <string.h>

char buffer[10000];
int bigNum[500];
int bigTop;
int hash[500]; int tMod[5][505];

void strToBigNum(){
	int length = strlen(buffer);
	int leadingZero = (3 - (length % 3))%3;

	char output[10100] = {'\0'};
	if(leadingZero == 1){
		output[0] = '0'; output[1] = '\0';
	}else if(leadingZero == 2){
		output[0] = '0'; output[1] = '0'; output[2] = '\0';
	}

	strcat(output, buffer);

	length += leadingZero;
	bigTop = length /3;
	int i;
	for(i=bigTop-1; i >= 0; --i){
		sscanf(output, "%3d%s", &bigNum[i], output);
	}
}

int thousandMod(int N, int mod){
	int result = 1;
    int next = 1000%mod;
    if(N <505)
    	if(tMod[hash[mod]][N] != 0)
    		return tMod[hash[mod]][N];

	while(N--){
		result *= next;
		result %= mod;
	}
	tMod[hash[mod]][N] = result%mod;
	return result%mod;
}


int BigMod(int mod){
	int result = 0, i;
	for(i=bigTop-1;i>=0;--i){
		result += (bigNum[i]%mod * thousandMod(i, mod))%mod;
		result %= mod;
	}
	return result%mod;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10070.in", "r", stdin);
	freopen("q10070.out", "w", stdout);
	#endif

	int ordinary, leap, once = 0;
	hash[4] = 0; hash[15] = 1; hash[55] = 2; hash[100] = 3; hash[400] = 4;
	while(gets(buffer)!=NULL){
		strToBigNum();
		ordinary = 1;
		leap = 0;

		if(once == 1)
			putchar(10);

		if(BigMod(400) == 0 || (BigMod(4) == 0 && BigMod(100) != 0)){
			puts("This is leap year.");
			ordinary = 0;
			leap = 1;
		}

		if(BigMod(15) == 0){
			puts("This is huluculu festival year.");
			ordinary = 0;
		}

		if(leap == 1 && BigMod(55) == 0){
			puts("This is bulukulu festival year.");
			ordinary = 0;
		}

		if(ordinary == 1)
			puts("This is an ordinary year.");

		once = 1;
	}
	return 0;
}
