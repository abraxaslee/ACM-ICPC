//q146.cpp - 2011/10/22
//accepted at 
//run time = 0.008 / 0.004 c
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q146.in", "r", stdin);
	freopen("q146.out", "w", stdout);
	#endif

	char buffer[55];
	while(true){
		gets(buffer);
		if(buffer[0] == '#')
			break;
		int length = strlen(buffer);
		if( next_permutation(buffer, buffer+length)){
			puts(buffer);
		}else{
			puts("No Successor");
		}
	}
	return 0;
}
