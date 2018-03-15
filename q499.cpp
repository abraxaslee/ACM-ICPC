//q499.cpp - 2011/09/26
//accepted at 2011-09-26 02:55:51
//run time = 0.020
#include <stdio.h>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
	char c;

	caseStart:
	int upper[26] = {0};
	int lower[26] = {0};
	int maxNum = 0;
	while((c=getchar())!='\n'){

		if(c==EOF){return 0;}

		if(isupper(c)){
			upper[c-65] += 1;
			maxNum = max(maxNum,upper[c-65]);
		}else if(islower(c)){
			lower[c-97] += 1;
			maxNum = max(maxNum,lower[c-97]);
		}
	}
	if(maxNum>0){
		for(int i=0;i<26;i++){
			if(upper[i]==maxNum){
				printf("%c", i+65);
			}
		}
		for(int i=0;i<26;i++){
			if(lower[i]==maxNum){
				printf("%c", i+97);
			}
		}
	printf(" %d\n", maxNum);
	}
	goto caseStart;
	return 0;
}
