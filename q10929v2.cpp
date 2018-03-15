//q10929v2.cpp - 2011/11/20
//accepted at 
//run time = 0.016
#include <stdio.h>

char buffer[1005];

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10929.in", "r", stdin);
	freopen("q10929.out", "w", stdout);
	#endif

	int i;
	while(gets(buffer)!=NULL){
		if(buffer[0] =='0' && buffer[1] == '\0')
			break;

		int sum[2] = {}; int index = 0;

		for(i=0;buffer[i]!='\0';++i, index^=1)
			sum[index] += buffer[i] - 48;

		if((sum[1] - sum[0])%11){
			printf("%s is not a multiple of 11.\n", buffer);
		}else{
			printf("%s is a multiple of 11.\n", buffer);
		}
	}
	return 0;
}
