//Q102: Ecological Bin Packing
//accepted at 2011-09-26 01:25:13
//run time = 0.028

#include <stdio.h>
using namespace std;
bool compareLower(int moves, int currentmin);

int main(){

	struct bin{
		   char bname;
		   int B,C,G;
	};
	int min, totalmoves, currentMoves;
	min = 0;
	totalmoves = 0;
	currentMoves = 0;

	bin binA, binB, binC;
	
	while(scanf("%d %d %d %d %d %d %d %d %d", &binA.B,  &binA.G, &binA.C, &binB.B, &binB.G, &binB.C, &binC.B, &binC.G, &binC.C)!=EOF){
	
	totalmoves = binA.B + binA.C + binA.G + binB.B + binB.C + binB.G + binC.B + binC.C + binC.G;
	min = totalmoves;
	currentMoves = totalmoves - binA.B - binB.C - binC.G;
		if (compareLower(currentMoves, min))
		{
			min = currentMoves;
			binA.bname = 'B';
			binB.bname = 'C';
			binC.bname = 'G';
		}
	currentMoves = totalmoves - binA.B - binB.G - binC.C;
		if (compareLower(currentMoves, min))
		{
			min = currentMoves;
			binA.bname = 'B';
			binB.bname = 'G';
			binC.bname = 'C';
		}
	currentMoves = totalmoves - binA.C - binB.B - binC.G;
		if (compareLower(currentMoves, min))
		{
			min = currentMoves;
			binA.bname = 'C';
			binB.bname = 'B';
			binC.bname = 'G';
		}
	currentMoves = totalmoves - binA.C - binB.G - binC.B;
		if (compareLower(currentMoves, min))
		{
			min = currentMoves;
			binA.bname = 'C';
			binB.bname = 'G';
			binC.bname = 'B';
		}
	currentMoves = totalmoves - binA.G - binB.B - binC.C;
		if (compareLower(currentMoves, min))
		{
			min = currentMoves;
			binA.bname = 'G';
			binB.bname = 'B';
			binC.bname = 'C';
		}
	currentMoves = totalmoves - binA.G - binB.C - binC.B;
		if (compareLower(currentMoves, min))
		{
			min = currentMoves;
			binA.bname = 'G';
			binB.bname = 'C';
			binC.bname = 'B';
		}
	printf("%c%c%c %d\n", binA.bname, binB.bname, binC.bname, min);
	}
	return 0;
}

bool compareLower(int moves,int currentmin)
{
	if ( moves < currentmin)
	{
		return true;
	}else{
		return false;
	}
}
