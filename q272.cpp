//Q272: TeX Quotes
//q272.cpp - 2011/08/29
//accepted at 2011-08-29 03:54:00
//run time = 0.016

#include <stdio.h>
using namespace std;

int main(){
	char inputChar;
	bool flagA=false;
	while(scanf("%c",&inputChar) != EOF){
		if(inputChar == -1){return 0;}
		if(inputChar != 34){
			printf("%c",inputChar);
		}else{
			if(flagA){
				printf("%c%c", 39, 39);
				flagA = false;
			}else{
				printf("%c%c", 96, 96);
				flagA = true;
			}

		}
	}
	return 0;
}
