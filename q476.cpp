//Q476: Points in Figures: Rectangles
//q476.cpp - 2011/08/29
//accepted at 2011-08-29 12:17:29
//run time = 0.016

#include <stdio.h>
using namespace std;

int main(){
	float rSX[10],rSY[10],rEX[10],rEY[10];
	char rTag;
	int i=0;
	while(scanf("%c", &rTag)!=EOF){
		if(rTag==052){break;}
		scanf("%f %f %f %f\n", &rSX[i], &rSY[i], &rEX[i], &rEY[i]);
		i++;
	}
	float starX,starY;
	int pointNum = 0;
	bool flagA = false;
	while(scanf("%f %f", &starX, &starY)!=EOF){
		if(starX == 9999.9f && starY == 9999.9f){break;}
		pointNum++;
		flagA = false;
		for(int j=0;j<i;j++){
			if(starX > rSX[j] && starX < rEX[j] && starY < rSY[j] && starY > rEY[j]){
				printf("Point %d is contained in figure %d\n", pointNum, j+1);
				flagA = true;
				}
		}
		if(flagA==false){printf("Point %d is not contained in any figure\n", pointNum);}
	}
	return 0;
}
