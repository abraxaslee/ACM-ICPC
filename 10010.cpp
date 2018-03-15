//2012/02/14
//10010.cpp
//Run time: 0.012

#include <stdio.h>

char grid[50][55], check[55];
char rev[300];
int row, col, once;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1};


int DFS(int x, int y){
	if(grid[x][y] != check[0] & grid[x][y] != rev[check[0]])	return 0;
	if(check[1] == '\0') return 1;
	int i, nx, ny;
	for(i=0; i<8; ++i){
		nx = x + dx[i], ny = y + dy[i];
		if(0 <= nx & 0 <= ny & nx < row & ny < col)
			if(grid[nx][ny] == check[1] | grid[nx][ny] == rev[check[1]])
				if(search(nx, ny, i, 2))
					return 1;
	}
	return 0;
}

int search(int x, int y, int dir, int pos){
	if(check[pos] == '\0') return 1;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if(0 <= nx & 0 <= ny & nx < row & ny < col)
		if(grid[nx][ny] == check[pos] | grid[nx][ny] == rev[check[pos]])
			return search(nx, ny, dir, pos+1);
	return 0;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10010.in", "r", stdin);
	freopen("10010.out", "w", stdout);
	#endif

	int caseNum, i, j, query;

	for(i=65; i<91; ++i)
		rev[i] = i+32, rev[i+32] = i;
	scanf("%d", &caseNum);
	while(caseNum--){

		scanf("%d%d", &row, &col); getchar();

		for(i=0; i<row; ++i)
			gets(grid[i]);

		if(once) putchar(10);

		scanf("%d", &query); getchar();

		while(query--){
			gets(check);
			for(i=0; i<row; ++i)
				for(j=0; j<col; ++j)
					if(DFS(i, j))
						{printf("%d %d\n", i+1, j+1); i=row, j = col;}
		}
		once = 1;
	}
	return 0;
}
