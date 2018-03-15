//Q494: Kindergarten Counting Game
//accepted at
//run time = 0.020

#include <stdio.h>

inline bool ifWords(char inChar){

	if((inChar >=65&&inChar<=90 )||( inChar>=97&&inChar<=122)){
		return true;
	}else{
		return false;
	}
	return false;
}

int main(){
	char inputString[5000];
	int wordsNum;
	while(gets(inputString)){
		wordsNum = 0;
		for(int i=0;inputString[i]!='\0';i++){
			if(!ifWords(inputString[i+1])){
				if(ifWords(inputString[i])){
					wordsNum++;
				}
			}
		}
		printf("%d\n", wordsNum);
	}
	return 0;
}


