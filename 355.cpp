//2012/03/08
//355.cpp
//Run time: 0.008

#include <stdio.h>
#include <string.h>

char num[25], ans[55];
int hash[300], digit[16];
int length;

void build_hash(){
	hash['0'] = 0;	digit[0] = '0';
	hash['1'] = 1;	digit[1] = '1';
	hash['2'] = 2;	digit[2] = '2';
	hash['3'] = 3;	digit[3] = '3';
	hash['4'] = 4;	digit[4] = '4';
	hash['5'] = 5;	digit[5] = '5';
	hash['6'] = 6;	digit[6] = '6';
	hash['7'] = 7;	digit[7] = '7';
	hash['8'] = 8;	digit[8] = '8';
	hash['9'] = 9; 	digit[9] = '9';
	hash['A'] = 10;	digit[10] = 'A';
	hash['B'] = 11;	digit[11] = 'B';
	hash['C'] = 12;	digit[12] = 'C';
	hash['D'] = 13;	digit[13] = 'D';
	hash['E'] = 14;	digit[14] = 'E';
	hash['F'] = 15;	digit[15] = 'F';
}

int isValid(int base){
	static int i, valid;
	valid = base;
	for(i = 0; i < length; ++i)
		if(hash[num[i]] >= valid )
			return 0;
	return 1;
}

long long int anyToTen(int base){
	static int i;
	static long long int TEN, multi;
	TEN = 0, multi = 1;
	for(i=length-1; i>=0; --i, multi *= base){
		TEN += hash[num[i]] * multi;
	}
	return TEN;
}

void tenToAny(long long int TEN, int base){
	static int i, top, j, res[50] = {};
	top = 0;
	while(TEN > 0){
		res[top++] = TEN % base;
		TEN /= base;
	}
	ans[top] = '\0';
	for(i=top-1, j=0; i>=0; --i, ++j)
		ans[j] = digit[res[i]];

	if(top == 0)	{
		ans[0] = '0';
		ans[1] = '\0';
	}
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("355.in", "r", stdin);
	freopen("355.out", "w", stdout);
	#endif

	int M, N, i;
	build_hash();
	while(scanf("%d%d%s", &M, &N, num) == 3){
		length = strlen(num);

		if(isValid(M) == 0){
			printf("%s is an illegal base %d number\n", num, M);
		}else{
			tenToAny(anyToTen(M), N);
			printf("%s base %d = %s base %d\n", num, M, ans, N);
		}
	}

	return 0;
}
