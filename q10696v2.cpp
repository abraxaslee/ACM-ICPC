//q10696v2.cpp - 2011/09/24
//accepted at 
//run time = 0.072
#include <stdio.h>

int main(){
	int inputNum;
	while((scanf("%d", &inputNum)!=EOF)&&inputNum>0){
		if(inputNum<=101){
			printf("f91(%d) = 91\n", inputNum);
		}else{
			printf("f91(%d) = %d\n",inputNum,inputNum-10);
		}
	}
	return 0;
}
