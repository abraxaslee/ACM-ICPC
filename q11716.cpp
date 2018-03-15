//q11716.cpp - 2011/12/10
//accepted at 
//run time = 0.008
#include <stdio.h>
#include <math.h>
#include <string.h>

char buff[10005];
int length, sLength;

int notValid(){
	double temp = sqrt(length);
	sLength = (int) temp;
	if(temp == sLength)
		return 0;
	return 1;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11716.in", "r", stdin);
	freopen("q11716.out", "w", stdout);
	#endif

	int caseNum, i, j;
	scanf("%d", &caseNum); getchar();
	while(caseNum--){
		gets(buff);
		length = strlen(buff);
		if(notValid())
			puts("INVALID");
		else{
			for(i = 0 ; i < sLength; ++i)
				for(j = i; j < length ; j += sLength)
					putchar(buff[j]);

			putchar(10);
		}
	}
	return 0;
}
