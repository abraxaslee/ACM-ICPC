//q10922.cpp - 2011/11/09
//accepted at 
//run time = 0.012 / 0.028 c
#include <stdio.h>

char buffer[1005];

inline int NineDegree(int n, int degree){
	int result = 0;
	while(n > 0){
		result += n%10;
		n /= 10;
	}

	if(result==9){
		return degree;
	}

	if(result>9){
		return NineDegree(result, degree+1);
	}

	return 0;
}

inline int getInput(void){
	int input = 0, i;

	gets(buffer);

	for(i=0;buffer[i]!='\0';++i)
		input += buffer[i]-48;

	if(input == 0){
		return -1;
	}

	return input;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10922.in", "r", stdin);
	freopen("q10922.out", "w", stdout);
	#endif

	int inputNum, nDegree;
	while(true){
		inputNum = getInput();
		if(inputNum == -1){
			break;
		}
		if(inputNum == 9){
			printf("%s is a multiple of 9 and has 9-degree 1.\n", buffer);
		}else{
			nDegree = NineDegree(inputNum,2);

			if(nDegree > 0){
				printf("%s is a multiple of 9 and has 9-degree %d.\n", buffer, nDegree);
			}else{
				printf("%s is not a multiple of 9.\n", buffer);
			}

		}
	}

	return 0;
}
