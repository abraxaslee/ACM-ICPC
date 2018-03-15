//Q591:Box of Bricks
//q591.cpp - 2011/08/28
//accepted at 2011-08-28 14:55:22
//run time = 0.008

#include <stdio.h>
using namespace std;

int main(){
	int boxLen = 0;
	int setNum = 1;
	while(scanf("%d", &boxLen)!= EOF){
		int lenTotal = 0;
		int boxMean;
		int box[50];
		if(boxLen==0){break;}
		for(int i=0;i<boxLen;i++){
			scanf("%d", &box[i]);
			lenTotal += box[i];
		}
		boxMean = lenTotal/boxLen;
		int minMoves = 0;
		for(int i=0;i<boxLen;i++){
			 minMoves += (box[i]>= boxMean)? (box[i] - boxMean) : (boxMean - box[i]);
		}
		minMoves = minMoves >> 1;
		printf("Set #%d\n", setNum);
		printf("The minimum number of moves is %d.\n\n", minMoves);
		setNum++;
	}
	return 0;
}
