//Q477: Points in Figures: Rectangles and Circles
//q477.cpp - 2011/08/30
//accepted at 2011-09-01 05:56:15
//uva Runtime	0.020

#include <stdio.h>
using namespace std;

struct rFigure{
	float rSX, rSY, rEX, rEY;
	int fNum;
};

struct cFigure{
	float cX, cY, cC;
	int fNum;
};

int main(){
	char tempTag;
	int rfN = 0; // rfigure Number : default = 0
	int cfN = 0; // cfigure Number ; default = 0
	rFigure regtangle[10];
	cFigure circle[10];
	int figureNum = 0;
	bool flagInput = true;
	while(flagInput){
		scanf("%c", &tempTag);
		switch(tempTag){
			case 052:
				flagInput = false;
				break;
			case 'r':
				scanf("%f %f %f %f", &regtangle[rfN].rSX, &regtangle[rfN].rSY, &regtangle[rfN].rEX, &regtangle[rfN].rEY);
				figureNum++;
				regtangle[rfN].fNum = figureNum;
				rfN++;
				break;
			case 'c':
				scanf("%f %f %f", &circle[cfN].cX, &circle[cfN].cY, &circle[cfN].cC);
				figureNum++;
				circle[cfN].fNum = figureNum;
				cfN++;
				break;
		}
	}

	// start of testing input

	float starX, starY;
	int pointNum = 0;
	bool flagFound = false;


	while(!flagInput){

		scanf("%f %f", &starX, &starY);
		if(starX==9999.9f&&starY==9999.9f){break;}

		pointNum++;
		flagFound = false;

		for(int i=0;i<rfN;i++){
			if(starX>regtangle[i].rSX && starX<regtangle[i].rEX && starY<regtangle[i].rSY && starY>regtangle[i].rEY){
				printf("Point %d is contained in figure %d\n", pointNum, regtangle[i].fNum);
				flagFound = true;
			}
		}

		for(int i=0;i<cfN;i++){
			double temp, temp2;
			temp = (((starX-circle[i].cX)*(starX-circle[i].cX))+((starY-circle[i].cY)*(starY-circle[i].cY)));
			temp2 = (circle[i].cC*circle[i].cC);
			if(temp<temp2){
				printf("Point %d is contained in figure %d\n", pointNum, circle[i].fNum);
				flagFound = true;
			}
		}

		if(flagFound==false){printf("Point %d is not contained in any figure\n", pointNum);}

	}


	return 0;
}
