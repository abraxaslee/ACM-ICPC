//q871.cpp - 2011/12/11
//accepted at 
//run time = 0.004
#include <stdio.h>

char grid[30][30];
int top, count;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int max(int A, int B){
	return A>B? A:B;
}

void DFS(int x, int y){
	grid[x][y] = '0';
	count += 1;
	int i;
	for(i=0; i<8; ++i){
		int nx = x +dx[i];
		int ny = y +dy[i];
		if(0 <= nx && nx < top && 0 <= ny && ny < top)
			if(grid[nx][ny] == '1')
				DFS(nx, ny);
	}
	return;
}
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q871.in", "r", stdin);
	freopen("q871.out", "w", stdout);
	#endif

	int caseNum, maxBlock, i, j, once = 0;
	scanf("%d", &caseNum);	getchar(); 	getchar();
	while(caseNum--){
		top = maxBlock = 0;
		gets(grid[top]);
		while(grid[top++][0] != '\0')
			gets(grid[top]);

		for(i=0; i<top; ++i)
			for(j=0; grid[i][j] != '\0'; ++j)
				if(grid[i][j] == '1'){
					count = 0;
					 DFS(i, j);
					 maxBlock = max(maxBlock, count);
				}
		if(once)
			putchar(10);
		printf("%d\n", maxBlock);
		once =1;
	}

	return 0;
}
