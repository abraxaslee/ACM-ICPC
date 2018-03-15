//q11879.cpp - 2011/11/19
//accepted at
//run time = 0.024
#include <stdio.h>
#include <string.h>

char buffer[105];
int bigNum[50];
int bigTop;

void strToBigNum(){
	int length = strlen(buffer);
	int leadingZero = (3 - (length % 3))%3;

	char output[105] = {'\0'};
	if(leadingZero == 1){
		output[0] = '0'; output[1] = '\0';
	}else if(leadingZero == 2){
		output[0] = '0'; output[1] = '0'; output[2] = '\0';
	}

	strcat(output, buffer);

	length += leadingZero;
	bigTop = length /3;
	int i;
	for(i=bigTop-1; i >= 0; --i){
		sscanf(output, "%3d%s", &bigNum[i], output);
	}
}

int thousandMod(int N){
	int result = 1;
	while(N--){
		result *= 14;
		result %= 17;
	}
	return result%17;
}


int BigMod(){
	int result = 0, i;
	for(i=bigTop-1;i>=0;--i)
		result += (bigNum[i]%17 * thousandMod(i))%17;

	return result%17;
}

int main(){
	while(gets(buffer)!=NULL){
		if(buffer[0]=='0'&&buffer[1]=='\0')
			break;

		strToBigNum();

		if(BigMod()==0)
			puts("1");
		else
			puts("0");
	}
	return 0;
}
