//q10683.cpp - 2011/12/24
//accepted at 
//run time = 0.068
#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10683.in", "r", stdin);
	freopen("q10683.out", "w", stdout);
	#endif

	int HH, MM, SS, CC, output;
	char buff[10];
	while(gets(buff)!=NULL){
		sscanf(buff, "%2d%2d%2d%2d", &HH, &MM, &SS, &CC);
		output = HH*60;
		output += MM;
		output *= 60;
		output += SS;
		output *= 100;
		output += CC;
		output /= 0.864;
		printf("%07d\n", output);
	}

	return 0;
}
