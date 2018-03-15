//q713.cpp - 2011/11/04
//accepted at 
//run time = 0.008
#include <stdio.h>
#include <string.h>
char output[500] = {}; char* stringA; char* stringB;
inline void ReverseBigAdd(void){
	bool endA = false, endB = false; bool carry = false;
	int i = 0;
	while(endA == false || endB == false){
		if(carry){
			output[i] = 1;
			carry = false;
		}else
			output[i] = 0;

		if(!endA){
			if(stringA[i] == '\0')
				endA = true;
			else
				output[i] += stringA[i] - '0';
		}

		if(!endB){
			if(stringB[i] == '\0')
				endB = true;
			else
				output[i] += stringB[i] - '0';
		}

		if(output[i] >= 10){
			carry = true;
			output[i] -= 10;
		}
		output[i] += 48;
		i++;
	}
	output[i] = '\0';

	if(i>0){
		i--;
		while(output[i] == '0')
			output[i] = '\0';
	}

	int z = 0;
	while(output[z] == '0')
		z++;

	for(;output[z]!='\0';++z)
		putchar(output[z]);

	putchar(10);
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q713.in", "r", stdin);
	freopen("q713.out", "w", stdout);
	#endif

	int caseNum; char buffer[500];
	scanf("%d", &caseNum); getchar();
	while(caseNum--){
		gets(buffer);
		stringA = strtok(buffer, " "); stringB = strtok(NULL, " ");
		ReverseBigAdd();
	}
	return 0;
}
