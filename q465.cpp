//q465.cpp - 2011/10/30
//accepted at 
//run time = 0.008
#include <stdio.h>
#include <string.h>
#define INT_MAX 2147483647

char buffer[100000];
char FirstNum[100000];
char SecondNum[100000];
bool zeroFirst = false, zeroSecond = false;

bool bigFirst(void){
	for(int i=0;i<9;i++){
		if(FirstNum[i] == '\0')
			return false;
	}

	double tmp = 0;
	int i = 0;
	while(FirstNum[i]=='0'){
		i++;
	}
	for(;FirstNum[i]!='\0';i++){
		if(FirstNum[i]==' ')
			continue;
		tmp *= 10;
		tmp += FirstNum[i] - 48;
		if(tmp > INT_MAX){
			return true;
		}
	}
	if(tmp==0)
		zeroFirst = true;
	return false;
}

bool bigSecond(void){

	for(int i=0;i<9;i++){
		if(SecondNum[i] == '\0')
			return false;
	}

	double tmp = 0;
	int i = 0;
	while(SecondNum[i]!='\0'&&SecondNum[i]=='0'){
		i++;
	}
	for(;SecondNum[i]!='\0';i++){
		if(SecondNum[i]==' ')
			continue;
		tmp *= 10;
		tmp += SecondNum[i] - 48;
		if(tmp > INT_MAX)
			return true;
	}
	if(tmp == 0)
		zeroSecond = true;
	return false;
}

void addCheck(){
	double tmp = 0, tmp2 = 0;
	int i=0;
	while(FirstNum[i]!='\0'&&FirstNum[i]=='0')
		i+=1;

	for(;FirstNum[i]!='\0';i++){
		if(FirstNum[i]==' ')
			continue;
		tmp *= 10;
		tmp += FirstNum[i] - 48;
	}
	i=0;
	while(FirstNum[i]!='\0'&&FirstNum[i]=='0')
			i+=1;
	for(;SecondNum[i]!='\0';i++){
		if(SecondNum[i]==' ')
			continue;
		tmp2 *= 10;
		tmp2 += SecondNum[i] - 48;
	}
	if(tmp+tmp2 > INT_MAX){
		puts("result too big");
	}
	return;
}

void multiCheck(){
	double remaind = INT_MAX;
	double tmp = 0, tmp2 = 0;
	for(int i=0;FirstNum[i]!='\0';i++){
		if(FirstNum[i]==' ')
			continue;
		tmp *= 10;
		tmp += FirstNum[i] - 48;
	}
	for(int i=0;SecondNum[i]!='\0';i++){
		if(SecondNum[i]==' ')
			continue;
		tmp2 *= 10;
		tmp2 += SecondNum[i] - 48;
	}
	remaind /= tmp2;
	if(tmp > remaind){
		puts("result too big");
	}
	return;
}

char sign(){
	for(int i=0;buffer[i]!='\0';++i){
		if(buffer[i] == '+')
			return '+';
		if(buffer[i] == '*')
			return '*';
	}
	return -1;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q465.in", "r", stdin);
	freopen("q465.out", "w", stdout);
	#endif

	char* cPtr; char charSign;
	while(gets(buffer)!=NULL){
		puts(buffer);
		charSign = sign();
		cPtr = strtok(buffer, " *+");
		strcpy(FirstNum, cPtr);
		cPtr = strtok(NULL, " *+");
		strcpy(SecondNum, cPtr);

		zeroFirst = false, zeroSecond = false;
		bool bigF = bigFirst(), bigS = bigSecond();
		if(bigF == true)
			puts("first number too big");
		if(bigS == true)
			puts("second number too big");

			if(charSign == '+'){
				if(bigF || bigS)
					puts("result too big");
				else
					addCheck();
			}else{
				if(zeroFirst || zeroSecond)
					continue;
				else
					multiCheck();
			}
	}
	return 0;
}
