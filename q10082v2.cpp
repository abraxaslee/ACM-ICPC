//q10082v2.cpp - 2011/09/09
//10082 - WERTYU
//accepted at 
//run time = 0.012
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	char ch[]={'`','1','2','3','4','5','6','7','8','9','0','-','=',
	               'Q','W','E','R','T','Y','U','I','O','P','[',']','\\',
	               'A','S','D','F','G','H','J','K','L',';','\'',
	               'Z','X','C','V','B','N','M',',','.','/'};
	int maxLeng = 0;
	char inputChar[10000] = {0};
	int i = 0, j = 0;
	while(gets(inputChar)!=NULL){
		maxLeng = strlen(inputChar);
		for(i=0;i<maxLeng;i++){
			if(inputChar[i]==' '){
				printf(" ");
			}else{
				for(j=0;j<strlen(ch);j++){
					if(inputChar[i]==ch[j]){
						printf("%c", ch[j-1]);
						break;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
