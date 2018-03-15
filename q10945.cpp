//q10945.cpp - 2012/01/03
//accepted at 
//run time = 0.004
#include <stdio.h>

char buff[1000];
int stack[1000];
int top, i;

int reword(int c){
	if(c >= 65 & c<=90)
		return c;
	else if(c >= 97 & c <= 122)
		return c-32;
	return 0;
}

int solve(){
	top = 0;
	for(i=0; buff[i] != '\0'; ++i){
		stack[top] = reword(buff[i]);
		if(stack[top] > 0)
			top++;
	}

	int half = top-- / 2;
	for(i=0; i<half; ++i)
		if(stack[i] != stack[top-i])
			return 0;
	return 1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10945.in", "r", stdin);
	freopen("q10945.out", "w", stdout);
	#endif

	while(gets(buff)!=NULL){
		if(buff[4] == '\0' & buff[0] == 'D' & buff[1] == 'O' & buff[2] == 'N' & buff[3] == 'E')	break;

		if(solve())
			puts("You won't be eaten!");
		else
			puts("Uh oh..");
	}
	return 0;
}
