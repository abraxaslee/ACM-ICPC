//q10500v2.cpp - 2011/12/29
//accepted at 
//run time = 
#include <stdio.h>

char bar[] = {"|---|---|---|---|---|---|---|---|---|---|\0"};
int row, col, move;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


void BFS(int x, int y, int g[11][11], int v[11][11], int o[11][11]){
	v[x][y] = 1;
	o[x][y] = o[x-1][y] = o[x+1][y] = o[x][y-1] = o[x][y+1] = 1;

	int i, nx, ny;
	for(i=0; i<4; ++i){
		nx = x +dx[i], ny = y+dy[i];
		if(!v[nx][ny] && g[nx][ny] == '0'){
			BFS(nx,ny,g,v,o);	move++;
			return;
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

		int grid[11][11] = {};
		row += 1;
		col += 1;
		getchar();
		for(i=1; i<row; ++i)
			for(j=1; j<col; ++j){
				grid[i][j] = getchar();
				getchar();
			}

		int visit[11][11] = {};
		int open[11][11] = {};
		BFS(x,y, grid, visit, open);

		putchar(10);
		bar[4*(col-1) +1] = '\0';
		puts(bar);
		for(i=1; i<row; ++i){
			for(j=1; j<col; ++j)
				printf("| %c ", !open[i][j] ? '?': grid[i][j]);
			putchar('|'); putchar(10); puts(bar);
		}
		putchar(10);
		printf("NUMBER OF MOVEMENTS: %d\n", move);
		bar[4*(col-1) +1] = '-';
	}
	return 0;
}
