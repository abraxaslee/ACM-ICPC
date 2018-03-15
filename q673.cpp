//q673.cpp - 2011/09/17
//accepted at 
//run time = 0.048
#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	int caseNum = 0;
	char inputChar[132];
	bool flagFail = false;
	scanf("%d", &caseNum);
	getchar();

	StartGame:

	flagFail = false;
	gets(inputChar);
	stack<int> myStack;
	for(int i=0;inputChar[i]>0;i++){
		switch(inputChar[i]){
			case 40:
				myStack.push(40);
				continue;
			case 41:
				if(!myStack.empty()&&myStack.top()==40){
					myStack.pop();
				}else{
					flagFail = true;
					goto EndGame;
				}
				continue;

			case 91:
				myStack.push(91);
				continue;
			case 93:
				if(!myStack.empty()&&myStack.top()==91){
					myStack.pop();
				}else{
					flagFail = true;
					goto EndGame;
				}
				continue;
			default:
				continue;
		}
	}
	if(!myStack.empty()){
		flagFail = true;
	}

	EndGame:
	if(flagFail){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	if(--caseNum>0){goto StartGame;}
	return 0;
}
