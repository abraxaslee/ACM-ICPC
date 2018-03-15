//q1260.cpp - 2011/09/16
//accepted at
//run time =
#include <stdio.h>
using namespace std;

int main(){
	int caseNum = 0;
	int listA[1000];
	scanf("%d", &caseNum);

	caseStart:
	int n = 0;
	scanf("%d", &n);


	scanf("%u", &listA[0]);
	int maxB = listA[0];
	int sumB = 0;
	for(int i=1;i<n;i++){
		scanf("%u", &listA[i]);
		if(listA[i]>=maxB){
			maxB = listA[i];
			sumB = sumB + i;
			continue;
		}else{
			int j=0;
			for(j=0;j<i;j++){
				if(listA[j]<=listA[i]){
					sumB += 1;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("listA[%d] = %d\n", i, listA[i]);
	}
	printf("%d\n", sumB);
	if(--caseNum == 0){return 0;}
	goto caseStart;
	return 0;
}
