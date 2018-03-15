//q11936.cpp - 2011/10/16
//accepted at 
//run time = 
#include <stdio.h>
using namespace std;

int tri[3];

int max(int inputA, int inputB){
	if(inputA > inputB){
		return inputA;
	}
	return inputB;
}

bool isValid(){
	for(int i=0;i<3;i++){
		if(tri[i]<=0){
			return false;
		}
	}
	int maxLength = max(tri[0], max(tri[1], tri[2]) );
	int restLength = tri[0] + tri[1] + tri[2] - maxLength;
	if(restLength <= maxLength){
		return false;
	}
	return true;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11936.in", "r", stdin);
	freopen("q11936.out", "w", stdout);
	#endif

	int caseNum;
	scanf("%d", &caseNum);
	while(caseNum-- >0){
		scanf("%d%d%d", &tri[0], &tri[1], &tri[2]);
		if( isValid() ){
			printf("OK\n");
		}else{
			printf("Wrong!!\n");
		}
	}
	return 0;
}
