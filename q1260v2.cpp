//q1260.cpp - 2011/09/16
//accepted at 2011-09-24 03:31:10
//run time = 0.028
#include <stdio.h>
using namespace std;

int main(){
	int caseNum = 0;
	scanf("%d", &caseNum);

	while(caseNum-- >0){

		int n = 0;
		int temp = 0, sumB = 0;
		int listA[1000] = {0};
		int top = 1, i = 0; //top +1 = total num
		scanf("%d", &n);
		scanf("%d", &listA[0]);
		n -= 1;
		while(n-- > 0){
			scanf("%d", &temp);
			for(i = top-1; i>=0&& temp<listA[i];i--){
				printf("listA[%d] = %d > temp\n", i, listA[i]);
				listA[i+1] = listA[i];
			}
			printf("%d set to listA[%d]\n", temp, i+1);
			listA[i+1] = temp;
			top += 1;
			for(int j=0;j<top;j++){
				printf("[%d] = %d\n", j , listA[j]);
			}
			printf("sumB += %d\n", i+1);
			sumB += i+1;
			printf("sumB = %d\n", sumB);
		}

		printf("%d\n", sumB);
	}
	return 0;
}

