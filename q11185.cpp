//q11185.cpp - 2011/09/28
//accepted at 
//run time = 0.008
#include <stdio.h>

int main(){
	int ten = 0;
	while((scanf("%d", &ten)!=EOF)&& (ten>=0)){
		if(ten==0){
			printf("0\n");
			continue;
		}else{
			char three[20] = {0};
			int top = 0;
			while(ten>0){
				three[top++] = ten%3;
				ten /= 3;
			}
			for(int j=top-1;j>=0;j--){
				printf("%d", three[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
