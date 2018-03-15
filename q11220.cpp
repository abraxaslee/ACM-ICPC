//q11220.cpp - 2011/10/09
//accepted at 
//run time = 0.008
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11220.in", "r", stdin);
	freopen("q11220.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0;
	scanf("%d\n", &caseNum);
	char* cPtr;
	while(caseNum--){
		currentCase += 1;
		int i = 0;

		printf("Case #%d:\n", currentCase);
		char inputString[2000] = {};
		while(gets(inputString)){
			if(inputString[0]== '\0'){
				if(caseNum > 0){
					putchar(10);
				}
				break;
			}

			cPtr = strtok(inputString," ");
			int j = 0;
			while(cPtr != NULL){
				if(strlen(cPtr)>=j&&cPtr[j]!=0){
					putchar(cPtr[j++]);
				}
				cPtr = strtok(NULL," ");
			}
			putchar(10);
		}
	}
	return 0;
}
