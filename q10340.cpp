//q10340.cpp - 2011/09/10
//accepted at 2011-09-10 05:12:48
//run time = 0.008
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	char stringBig[1000000];
	char *stringS;
	char *stringT;
	while(gets(stringBig)!=NULL){
		stringS = strtok(stringBig," ");
		stringT = strtok(NULL," ");
		fflush(stdin);
		bool validString[10000] = {false};
		int maxLengS = 0, maxLengT = 0;
		bool flagNo = false;
		int last_J = 0;
		maxLengS = strlen(stringS);
		maxLengT = strlen(stringT);

		for(int i=0;i<maxLengS;i++){
			for(int j=last_J;j<maxLengT;j++){
				if(stringS[i]==stringT[j]){
					last_J = j+1;
					validString[i] = true;
					break;
				}
			}
			if(validString[i]==false){
				flagNo = true;
				printf("No\n");
				break;
			}
		}
		for(int z=0;z<maxLengS&&!flagNo;z++){
			if(!validString[z]){
				flagNo = true;
				printf("No\n");
				break;
			}
		}
		if(!flagNo){
			printf("Yes\n");
		}
	}
	return 0;
}
