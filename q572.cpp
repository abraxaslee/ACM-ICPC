//q572.cpp - 2011/10/27
//accepted at 
//run time = 
#include <stdio.h>

char grid[105][105];
int row, col;

int dx[8] = { 1, 0, -1, -1, -1, 0, 1, 1};
int dy[8] = { 1, 1, 1, 0, -1, -1, -1, 0};

void DFS(int x, int y){
	grid[x][y] = '*';

	int i;
	for(i = 0; i < 8; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(grid[nx][ny] == '@' && nx >=0 && ny >=0 && nx <row && ny <col)
			DFS(nx, ny);
	}

	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q572.in", "r", stdin);
	freopen("q572.out", "w", stdout);
	#endif

	while(scanf("%d%d", &row, &col)!=EOF && row+col > 0 ){
		getchar();
		int i, j, count = 0;
		for(i=0; i<row ; ++i)
			gets(grid[i]);

		for(i=0; i<row ; ++i){
			for(j=0; j<col ;++j){
				if(grid[i][j] == '@'){
					DFS(i,j);
					++count;
				}
			}
		}

		printf("%d\n", count);
	}
	return 0;
}
