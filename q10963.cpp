//q10963.cpp - 2011/09/15
//Q10963: The Swallowing Ground
//accepted at 2011-09-15 14:54:01
//run time = 0.008
#include <stdio.h>
using namespace std;

int absReduct(int, int);

int main(){
	int caseNum = 0, caseNow = 0;
	scanf("%d", &caseNum);

	gameStart:
	caseNow += 1;
	int i_x = 0, i_y1 = 0 , i_y2 = 0;
	scanf("%d", &i_x);

	int loop_i = 1, commonDiff = 0;
	bool flagFail = false;

	scanf("%d %d", &i_y1, &i_y2);
	commonDiff = absReduct(i_y1,i_y2);
	while(loop_i<i_x){
		scanf("%d %d", &i_y1, &i_y2);
		if(!flagFail){
			if(commonDiff != absReduct(i_y1,i_y2)){
				flagFail = true;
			}
		}
		loop_i++;
	}
	if(caseNow>1){printf("\n");}

	if(flagFail){
		printf("no\n");
	}else{
		printf("yes\n");
	}
	if(caseNow == caseNum){ return 0;}
	goto gameStart;
	return 0;
}

int absReduct(int yA, int yB){
	int temp = yA - yB;
	if(temp<0){
		temp = -temp;
	}
	return temp;
}
