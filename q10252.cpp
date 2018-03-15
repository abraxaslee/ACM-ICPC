//q10252.cpp - 2011/09/25
//accepted at 2011-09-25 15:48:09
//run time = 0.008
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){

	char stringA[1100], stringB[1100];
	char c;
	while(gets(stringA)){
		int a[26] = {0};
		int b[26] = {0};
		for(int z=0;stringA[z]!='\0';z++){
			a[stringA[z]-97] += 1;
			//printf("a[%d]\n", stringA[z]-97);
		}

		gets(stringB);
		for(int z=0;stringB[z]!='\0';z++){
			b[stringB[z]-97] += 1;
			//printf("b[%d]\n", stringB[z]-97);
		}

		for(int i=0;i<26;i++){
			int temp = min(a[i],b[i]);
			for(int j=0;j<temp;j++){
				putchar(i+97);
			}
		}
	putchar(10);
	}
	return 0;
}
