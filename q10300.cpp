//q10300.cpp - 2011/09/09
//accepted at 2011-09-09 15:22:05
//run time = 0.008
#include <stdio.h>
using namespace std;

int main(){
	int caseNum = 0;
	int totalFarmer = 0;
	unsigned numA, numB, temp;
	unsigned finalPrize;
	scanf("%d", &caseNum);
	while(caseNum>0){
		scanf("%d", &totalFarmer);
		finalPrize = 0;
		for(int i=0;i<totalFarmer;i++){
			scanf("%d %d %d", &numA, &temp, &numB);
			finalPrize = finalPrize + (numA * numB);
		}
		printf("%d\n", finalPrize);
		caseNum -= 1;
	}
	return 0;
}
