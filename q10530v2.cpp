//q10530v2.cpp - 2011/09/21
//Q10530: Guessing Game
//accepted at 2011-09-21 16:09:14
//run time = 0.008
#include <stdio.h>
using namespace std;

int main(){
	int guessNum = 0;
	char resp[10];
	int highest = 11, lowest = 0;

	while(true){
	scanf("%d", &guessNum);
	if(guessNum == 0 ){break;}
	getchar();
	gets(resp);

	if(resp[0]=='t'&&resp[4]=='h'){
		if(guessNum<highest){
			highest = guessNum;
		}
	}else if(resp[0]=='t'&&resp[4]=='l'){
		if(guessNum>lowest){
			lowest = guessNum;
		}
	}else{
		if(lowest>highest||guessNum>=highest||guessNum<=lowest||(highest-lowest)==1){
			printf("Stan is dishonest\n");
		}else{
			printf("Stan may be honest\n");
		}
		highest = 11, lowest = 0;
	}

	}
	return 0;
}
