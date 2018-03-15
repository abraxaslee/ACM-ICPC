//q10222.cpp
//accepted at 2011-09-09 11:11:02
//run time = 0.012
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	char ch[]={'`','1','2','3','4','5','6','7','8','9','0','-','=',
	               'q','w','e','r','t','y','u','i','o','p','[',']','\\',
	               'a','s','d','f','g','h','j','k','l',';','\'',
	               'z','x','c','v','b','n','m',',','.','/'};
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
					if(inputChar[i]>=65&&inputChar[i]<=90){
						inputChar[i] += 32;
					}
					if(inputChar[i]==ch[j]){
						printf("%c", ch[j-2]);
						break;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
