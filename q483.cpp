//q483.cpp - 2011/09/18
//accepted at 
//run time = 0.008
#include <stdio.h>
#include <cstring>
using namespace std;

int main(){
	char inputChar[2000];
	char *pStr;
	int strlength = 0;
	while(gets(inputChar)){
		 pStr = strtok(inputChar," ");

		 while(pStr!=NULL){
			 strlength = strlen(pStr)-1;
			 for(int i=strlength;i>=0;i--){
				 printf("%c",pStr[i]);
			 }
			 pStr = strtok(NULL," ");
			 if(pStr!=NULL){
				 printf(" ");
			 }
		 }
		 printf("\n");
	}
	return 0;
}
