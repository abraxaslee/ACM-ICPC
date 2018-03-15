//q10452.cpp - 2011/11/24
//accepted at 
//run time = 
#include <stdio.h>

char cobbles[10][10];
char marcus[10] = {'@','I','E','H','O','V','A','#','\0'};
int dx[3] = { -1, 0, 0 };
int dy[3] = { 0, 1, -1 };
char ways[3][6] = {{'f','o','r','t','h','\0'},{'r','i','g','h','t','\0'},{'l','e','f','t','\0'}};
int path[10];
int row, col, pathTop;

void DFS(int x, int y, int step){
	if(step == 8)
		return;

	int i;
	for( i=0; i<3; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if( 0 <= nx && 0 <= ny && nx < row && ny < col)
			if( cobbles[nx][ny] == marcus[step]){
				path[pathTop++] = i;
				DFS( nx, ny, step+1 );
				return;
			}
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10452.in", "r", stdin);
	freopen("q10452.out", "w", stdout);
	#endif

	int testCase, i;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d%d", &row, &col);
		getchar();

		pathTop = 0;
		for(i=0;i<row;++i)
			gets(cobbles[i]);

		for(i=0;i<col;++i)
			if(cobbles[row-1][i] == '@'){
				DFS( row-1, i, 1 );
				break;
			};

		printf("%s", ways[path[0]]);
		for(i=1;i<pathTop;++i)
			printf(" %s", ways[path[i]]);
		putchar(10);
	}

	return 0;
}
