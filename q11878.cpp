//q11878.cpp - 2011/10/15
//accepted at 
//run time = 0.008 / 0.004
#include <stdio.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11878.in", "r", stdin);
	freopen("q11878.out", "w", stdout);
	#endif

	int num1, num2, iResult, correct = 0;
	char sign, tmp;
	char results[5];
	while(scanf("%d%c%d%c%s", &num1, &sign, &num2, &tmp, &results)!=EOF){
		if(results[0]==63){
			continue;
		}else{
			iResult = 0;
			for(int i=0;results[i]!='\0';i++){
					iResult *=10;
					iResult += results[i] - 48;
			}
		}

		if(sign == '+'){
			if(num1+num2 == iResult){
				correct += 1;
			}
		}else{
			if(num1-num2 == iResult){
				correct += 1;
			}
		}
	}
	printf("%d\n", correct);
	return 0;
}
