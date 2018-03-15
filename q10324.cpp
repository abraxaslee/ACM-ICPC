//q10324.cpp - 2012/01/03
//accepted at 
//run time = 
#include <stdio.h>
#include <string.h>
#define one 4294967296
#define zero 0
#define MAP(x) ((bit[x]>>(x&31))&1)


char buff[1000005];
unsigned int bit[31255];
int top, i, pos, length;

int outRange(int x){
	if(x >= 0 & x < length)
		return 0;
	return 1;
}

int inRange(int x){
	if( x >= length)
		return length-1;
	if( x < 0)
		return 0;
	return x;
}

void input(){
	for(i = pos = top = 0; buff[i] != '\0'; ++i){
		if(buff[i] == '1')
			bit[top] |= 1;

		bit[top] = bit[top] << 1;

		if(pos == 31){
			pos = 0;
			top++;
		}else{
			pos++;
		}
	}
	length = top*32 + pos;
	printf("length=%d, pos=%d, top=%d\n", length, pos, top);
}


int solve(int x, int y){

	if(x > y){
		int tmp = x;
		x = y;
		y = tmp;
	}
	if(outRange(x) & outRange(y))	return 0;
	x = inRange(x), y = inRange(y);
	printf("x=%d, y=%d\n", x, y);
	int target = 0;
	if(x % 32)
		target = bit[x/32] && 1  - x %32);
	printf("%d\n", target);

	return 1;
}
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10324.in", "r", stdin);
	freopen("q10324.out", "w", stdout);
	#endif

	int tmp, query, current = 0;
	while(gets(buff)!=NULL){
		memset(bit, 0, sizeof(bit));
		input();
		for(i=0; i<32; ++i)
			solve(i, 31);
	}

	return 0;
}
