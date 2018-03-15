//q444.cpp - 2011/09/23
//accepted at 2011-09-23 09:37:23
//run time = 0.020
#include <stdio.h>
#include <cctype>
#include <stack>
using namespace std;

char inputChar[300];
stack<int> mystack;

void encode(){
	int temp = 0;
	for(int i = 0 ;inputChar[i] != '\0'; i++){
		while(inputChar[i]>0){
			temp *= 10;
			temp += inputChar[i] %10;
			inputChar[i] /= 10;
		}
		mystack.push(temp);
		temp = 0;
	}
	while(!mystack.empty()){
		if(mystack.top()==1||mystack.top()==11||mystack.top()==21){
			printf("%03d", mystack.top());
		}else{
			printf("%02d", mystack.top());
		}
		mystack.pop();
	}
	printf("\n");
	return;
}

void decode(){
	int j = 1;
	char temp = 0;
	for(int i = 0 ;inputChar[i] != '\0'; i++){
		temp += (inputChar[i] - 48) * j;
		j*=10;
		if(isprint(temp)){
			mystack.push (temp);
			temp = 0;
			j = 1;
		}
	}
	while(!mystack.empty()){
			printf("%c", mystack.top());
			mystack.pop();
		}
		printf("\n");
	return;
}

int main(){
	while(gets(inputChar)!=NULL){
		if(isdigit(inputChar[0])){
			decode();
		}else{
			encode();
		}
	}
	return 0;
}
