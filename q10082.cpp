//q10082.cpp - 2011/09/08
//10082 - WERTYU
//accepted at 2011-09-09 10:14:55
//run time = 0.012
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	char ch[] = {'0','-','=','Q','W','E','R','T','Y','U','I','O','P','[',']','\\','A','S','D','F','G','H','J','K','L',';','\'','Z','X','C','V','B','N','M',',','.','/'}; //[35] is .  [36] is /
	int maxLeng = 0;
	char inputChar[10000] = {0};
	int i = 0, j = 0;
	while(gets(inputChar)!=NULL){
		maxLeng = strlen(inputChar);
		for(i=0;i<maxLeng;i++){
			if(inputChar[i]==' '){
				printf(" ");
				}
			else if(inputChar[i]>48&&inputChar[i]<58){
				if(inputChar[i]=='0'){
					printf("9");
					continue;
				}
				else if(inputChar[i]=='1')
				{
					printf("`");
					continue;
				}else{
					printf("%c", inputChar[i]-1);
				}
				}
			else{
				for(j=0;j<37;j++){
					if(inputChar[i]==ch[j]){
						printf("%c", ch[j-1]);
						inputChar[i] = 0;
						break;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
