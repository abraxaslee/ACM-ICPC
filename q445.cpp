//q445.cpp - 2011/09/18
//accepted at 2011-09-18 09:26:59
//run time = 0.016
#include <stdio.h>
#include <cstring>
using namespace std;

int main(){
	char inputChar[2000];
	int charCounter = 0, charLength = 0;
	char* pStr;
	while(gets(inputChar)){
		//read element of char string
		if(inputChar[0]=='\0'){printf("\n"); continue;}
		pStr = strtok(inputChar,"!");
		while(pStr!=NULL){
			for(int i=0; pStr[i]!='\0';i++){
				if(pStr[i]>=48&&pStr[i]<=57){
					charCounter = charCounter + pStr[i] - 48;
				}

				if(pStr[i]>=65||pStr[i]==42){
					if(pStr[i]=='b'){
						pStr[i] = ' ';
					}
					for(int j=charCounter;j>0;j--){
						printf("%c", pStr[i]);
					}
					charCounter = 0;
				}
			}
			printf("\n");
			pStr = strtok(NULL,"!");
		}
	}

	return 0;
}
