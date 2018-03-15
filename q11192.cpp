//q11192.cpp - 2011/11/19
//accepted at 
//run time = 0.004
#include <stdio.h>
#include <string.h>


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11192.in", "r", stdin);
	freopen("q11192.out", "w", stdout);
	#endif

	char buff[110];
	int G, length, R;

	while(scanf("%d ", &G)!=EOF && G > 0){

		gets(buff);
		length = strlen(buff);
		R = length / G;

		for(int i=0;i<length; i+=R)
			for(int j=i+R-1;j>=i;--j)
				putchar(buff[j]);
		putchar(10);

	}
	return 0;
}
