//q679.cpp - 2011/09/22
//accepted at 
//run time = 

//TLE version
#include <stdio.h>
using namespace std;

int main(){
	int caseNum;
	int deep, ball;

	scanf("%d", &caseNum);
	caseStart:
	bool root[1048575] = {false};
	scanf("%d %d", &deep, &ball);
	for(int j=1; j<=ball; j++){
		int rootNum = 1;
		for(int i=1;i<deep;i++){
			if(root[rootNum]){
				root[rootNum] = false;
				rootNum = (rootNum * 2) +1;
			}else{
				root[rootNum] = true;
				rootNum = rootNum * 2;
			}
		}
		printf("%d %d\n",j , rootNum);
	}
	if(--caseNum==0){return 0;}
	goto caseStart;
	return 0;
}
