//q11687.cpp - 2011/11/07
//accepted at 
//run time = 0.012 c
#include <stdio.h>
#include <string.h>

char buff[1000005];

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11687.in", "r", stdin);
	freopen("q11687.out", "w", stdout);
	#endif

	while(1){
		gets(buff);

		if(buff[0] == 'E')
			break;

		if(buff[0] == '1' && buff[1] == '\0'){
			puts("1");
			continue;
		}
		int n = strlen(buff);
		if( n == 1){
			puts("2");
			continue;
		}else if( n < 10){
			puts("3");
			continue;
		}else{
			puts("4");
			continue;
		}
	}
	return 0;
}
