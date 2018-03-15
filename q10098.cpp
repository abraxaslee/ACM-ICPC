//q10098.cpp - 2011/10/23
//accepted at 
//run time = 0.028
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10098.in", "r", stdin);
	freopen("q10098.out", "w", stdout);
	#endif

	int caseNum, length; char buffer[15];
	scanf("%d", &caseNum); getchar();
	while(caseNum--){

		gets(buffer);
		length = strlen(buffer);
		sort(buffer, buffer+length);
		do{
			puts(buffer);
		}while(next_permutation(buffer, buffer+length));
		putchar(10);
	}
	return 0;
}
