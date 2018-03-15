//q10500.cpp - 2011/12/29
//accepted at 
//run time = 0.016
#include <stdio.h>
#include <string.h>

char bar[] = {"|---|---|---|---|---|---|---|---|---|---|\0"};
int grid[10][15];
int visit[10][15];
int open[10][15];
int row, col, move;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


void BFS(int x, int y){
	visit[x][y] = 1;
	open[x][y] = 1;

	int i;
	int gone = 0;
	for(i=0; i<4; ++i){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if( 0 <= nx && 0 <= ny && nx < row && ny < col){
			open[nx][ny] = 1;
			if(!gone)
				if(grid[nx][ny] == '0')
					if(!visit[nx][ny]){
						BFS(nx,ny);
						move++;
						gone = 1;
					}
		}
	}
	return;
}


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10500.in", "r", stdin);
	freopen("q10500.out", "w", stdout);
	#endif

	int x, y, i, j;
	while(scanf("%d%d", &row, &col)==2){
		if(row+col == 0)	break;
		scanf("%d%d", &x, &y);
		move = 0;

		getchar();
		for(i=0; i<row; ++i)
			for(j=0; j<col; ++j){
				grid[i][j] = getchar();
				getchar();
			}

		memset(visit, 0, sizeof(visit));
		memset(open, 0, sizeof(open));
		BFS(x-1,y-1);

		putchar(10);
		bar[4*col+1] = '\0';
		puts(bar);
		for(i=0; i<row; ++i){
			for(j=0; j<col; ++j)
				printf("| %c ", open[i][j] == 0 ? '?': grid[i][j]);
			putchar('|'); putchar(10); puts(bar);
		}
		putchar(10);
		printf("NUMBER OF MOVEMENTS: %d\n", move);
		bar[4*col+1] = '-';
	}
	return 0;
}
