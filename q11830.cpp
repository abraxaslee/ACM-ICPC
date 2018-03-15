//q11830.cpp - 2011/12/26
//accepted at 
//run time = 0.004

#include <stdio.h>

char buff[105];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11830.in", "r", stdin);
	freopen("q11830.out", "w", stdout);
	#endif

	int leadingZero, broken, i;
	while(gets(buff)!=NULL){
		if(buff[0] == '0' && buff[2] == '0')		break;

		leadingZero = 1;
		broken = buff[0];

		for(i=2; buff[i] != '\0' ; ++i){

			if(buff[i] == broken)
				continue;
			else if(buff[i] == '0' && leadingZero)
				continue;

			leadingZero = 0;
			putchar(buff[i]);
		}

		if(leadingZero)
			putchar('0');

		putchar(10);
	}
	return 0;
}
