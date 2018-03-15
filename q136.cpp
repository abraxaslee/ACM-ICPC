//q136.cpp - 2011/09/24
//accepted at 
//run time = ----
#include <stdio.h>
using namespace std;

int ugly[2000] = {0};
int primeFactors[3];
int top = 1;

void sort(int inputNum){
	static int i;
	for(i=top-1;i>=0;i--){
			if(ugly[i] == inputNum){
				//printf("drop : %d\n", inputNum);
				return;
			}
		}
	for(i=top-1;i>=0 && inputNum < ugly[i];i--){
		ugly[i+1] = ugly[i];
	}
	ugly[i+1] = inputNum;
	top += 1;
}

void solve(int n){
	int z=0;
	while(z<n){
		for(int i=0;i<3;i++){
			//printf("sort : primeFactors[%d] * ugly[%d] = %u\n", i , z ,primeFactors[i] * ugly[z]);
			sort(primeFactors[i] * ugly[z]);
		}
		z++;
	}
}

int main(){
    time_t start, end ;
    time(&start) ;
	ugly[0] = 1;
	primeFactors[0] = 2;
	primeFactors[1] = 3;
	primeFactors[2] = 5;
	solve(1300);
	printf("\n 0:\n");
	for(int j=0;j<100;j++){
		printf("%d ",ugly[j]);
	}
	printf("\n 1400:\n");
	for(int j=1400;j<1500;j++){
		printf("%d ",ugly[j]);
		}
	printf("1500_%d ", ugly[1500]);
	printf("1499_%d ", ugly[1499]);
	return 0;
}
//The  1500'th ugly number is 859963392.
