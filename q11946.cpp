//q11946.cpp - 2011/11/10
//accepted at 
//run time = 0.008
#include <stdio.h>

char buffer[100];
char code[11] = {'O','I','Z','E','A','S','G','T','B','P','\0'};

inline bool isNumber(char c){
	if(c >= 48 && c <= 57){
		return true;
	}
	return false;
}

inline void decode(){
	for(int i=0;buffer[i]!='\0';++i){
		if(isNumber(buffer[i])){
			buffer[i] = code[buffer[i]-48];
		}
	}
	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11946.in", "r", stdin);
	freopen("q11946.out", "w", stdout);
	#endif

	int caseNum; bool once = false;
	scanf("%d\n", &caseNum);
	while(caseNum){
		if(gets(buffer) == NULL || buffer[0]=='\0'){
			--caseNum;
			if(caseNum>0)
				putchar(10);
		}else{
			decode();
			puts(buffer);
		}
	}
	return 0;
}
