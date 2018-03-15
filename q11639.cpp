//q11639.cpp - 2011/12/10
//accepted at 
//run time = 
#include <stdio.h>

struct POINT{
	int x;
	int y;
} A[4], B[4];

int absINT(int A){
	if(A < 0)
		return -A;
	return A;
}
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11639.in", "r", stdin);
	freopen("q11639.out", "w", stdout);
	#endif

	int caseNum, sizeA, sizeB, sizeEX, i, current = 0, tmp;
	scanf("%d", &caseNum);
	while(caseNum--){
		int AinB[4] = {}, BinA[4] = {}, top[2] = {};
		scanf("%d%d%d%d", &A[0].x, &A[0].y, &A[1].x, &A[1].y);
		scanf("%d%d%d%d", &B[0].x, &B[0].y, &B[1].x, &B[1].y);
		A[2].x = A[0].x; A[2].y = A[1].y; A[3].x = A[1].x; A[3].y = A[0].y;
		B[2].x = B[0].x; B[2].y = B[1].y; B[3].x = B[1].x; B[3].y = B[0].y;

		sizeA = (A[1].x - A[0].x) * (A[1].y - A[0].y);
		sizeB = (B[1].x - B[0].x) * (B[1].y - B[0].y);

		for(i=0;i<4; ++i)
			if( B[0].x <= A[i].x && A[i].x <= B[1].x && B[0].y <= A[i].y && A[i].y <= B[1].y)
				AinB[top[0]++] = i;

		for(i=0;i<4; ++i)
			if( A[0].x <= B[i].x && B[i].x <= A[1].x && A[0].y <= B[i].y && B[i].y <= A[1].y)
				BinA[top[1]++] = i;


		for(i=0; i<top[0]; ++i)
			printf("DEBUG : A: x%d = %d, y%d = %d\n", AinB[i]+1, A[AinB[i]].x, AinB[i]+1, A[AinB[i]].y);

		for(i=0; i<top[0]; ++i)
			printf("DEBUG : B: x%d = %d, y%d = %d\n", BinA[i]+1, B[BinA[i]].x, BinA[i]+1, B[BinA[i]].y);

		if(top[0] + top[1] == 0)
			sizeEX = 0;
		else if(top[0] + top[1] == 2){
			printf("DEBUG : sizeEX = %d * %d\n", absINT(A[AinB[0]].x - B[BinA[0]].x),  absINT(A[AinB[0]].y - B[BinA[0]].y));
			sizeEX = absINT(A[AinB[0]].x - B[BinA[0]].x) * absINT(A[AinB[0]].y - B[BinA[0]].y);
		}else if(top[0] + top[1] == 8)
			sizeEX = sizeA;
		else if(top[0] == 4)
			sizeEX = sizeA;
		else if(top[1] == 4)
			sizeEX = sizeB;

		tmp = sizeA + sizeB - sizeEX;
		printf("Night %d: %d %d %d\n", ++current, sizeEX, tmp - sizeEX, 10000 - tmp);
		printf("DEBUG : top[0] = %d, top[1] = %d\n", top[0], top[1]);
	}
	return 0;
}
