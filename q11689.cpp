//q11689.cpp - 2011/09/13
//accepted at 2011-09-14 10:38:15
//run time = 0.016
#include <stdio.h>
using namespace std;

int main(){
	int numE = 0, numF = 0, numC = 0;
	int caseNum = 0;
	scanf("%d ",&caseNum);
	while(caseNum-- >0){
		scanf("%d %d %d", &numE, &numF, &numC);
		int totalBottle = numE + numF, totalDrink=0, modBottle = 0;
			while(totalBottle>=numC){
				modBottle = totalBottle%numC;
				totalBottle /= numC;
				totalDrink += totalBottle;
				totalBottle += modBottle;
			}
		printf("%d\n", totalDrink);
	}
	return 0;
}
