//q11470.cpp - 2011/10/17
//accepted at 
//run time = 
#include <stdio.h>
#define INT_MAX 2147483647
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11470.in", "r", stdin);
	freopen("q11470.out", "w", stdout);
	#endif

	int dx[4] = { 0 , 1 , 0 , -1};
	int dy[4] = { 1 , 0 , -1 , 0 };
	int grid[10][10];

	int gridSize, currentCase = 0;
	while( scanf("%d", &gridSize) != EOF && gridSize > 0 ){

		for(int i=0;i<gridSize;i++){
			for(int j=0;j<gridSize;j++){
				scanf( "%d" , &grid[i][j] );
			}
		}
		printf("Case %d:", ++currentCase);
		int sX = 0, sY = 0, eX = 0, eY = 0, subSum = 0, totalGrid = gridSize * gridSize;
		if(grid[sX][sY] == INT_MAX){
			break;
		}else{
			subSum += grid[sX][sY];
			totalGrid -= 1;
			grid[sX][sY] = INT_MAX;
		}

		for(int i=0;i<4&&totalGrid>1;i++){
			while(sX + dx[i] >= 0 && sX + dx[i] < gridSize &&
				  sY + dy[i] >= 0 && sY + dy[i] < gridSize )
			{
					//if next step is legal
					sX += dx[i];
					sY += dy[i];

					//if next step has been taken
					if(grid[sX][sY] == INT_MAX){
						if(sX == eX && sY == eX){
							//it is a start point of a cycle
							if(subSum == 0){
								//empty
								i=5;
								break;
							}
							printf(" %d", subSum);
							subSum = 0;
							sX -= dx[i];
							sY -= dy[i];
							eX = sX;
							eY = sY;
							i = 0;
						}else{
							sX -= dx[i];
							sY -= dy[i];
							i++;
						}
					}else{
						subSum += grid[sX][sY];
						grid[sX][sY] = INT_MAX;
					}
			}
		}
		if(subSum != 0){
			printf(" %d", subSum);
		}
		putchar(10);
	}
	return 0;
}
