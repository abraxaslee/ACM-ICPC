//q299.cpp - 2011/09/29
//accepted at 
//run time = 0.008
#include <stdio.h>
using namespace std;

int main(){
	int caseNum;
	scanf("%d", &caseNum);
	while(caseNum-- >0){
		int L = 0;
		scanf("%d", &L);
		int myArray[51] = {};
		int optimalSwap = 0, i_temp = 0, mid = 0;
		for(int i=0,j=0;i<L;i++){
			scanf("%d", &i_temp);
			for(j=i-1;j>=0;j--){
				if(i_temp<myArray[j]){
					optimalSwap += 1;
					myArray[j+1] = myArray[j];
				}else{
					break;
				}
			}
			myArray[j+1] = i_temp;
		}
		/*for(int i=0;i<L;i++){
			printf("[%d] : %d\n", i, myArray[i]);
		}*/
		printf("Optimal train swapping takes %d swaps.\n", optimalSwap);
	}
	return 0;
}
