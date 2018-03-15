//Q482: Permutation Arrays
//q482.cpp - 2011/09/02
//accepted at 2011-09-03 13:14:53
//run time = 0.020

#include <stdio.h>
using namespace std;

int main(){
	int caseNum = 0;
	char tarNum[1000][1000];
	short int indexNum[1000];
	int icount;
	int mcount;
	while(scanf("%d", &caseNum)!=EOF){
		mcount = 0;
		icount = 0;
		while(true){
			scanf("%d", &indexNum[icount]);
			if(getchar()=='\n'){
				break;
			}
			printf("indexNum[%d] is %d\n", icount, indexNum[icount]);
			++icount;
		}
		mcount = icount;
		printf("mcount is %d\n", mcount);
		icount = 0;
		while(true){
			scanf("%s", tarNum[indexNum[icount]-1]);
			if(getchar()=='\n'){
							break;
			}
			printf("tarNum[%d] is %s\n", indexNum[icount]-1, tarNum[indexNum[icount]-1]);
			++icount;
		}
		for(icount = 0;icount<=mcount;icount++){
			printf("%s\n", tarNum[icount]);
		}
	}
	return 0;
}
