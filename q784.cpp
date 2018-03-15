//q784.cpp - 2011/10/26
//accepted at 
//run time = 0.054 / 0.024 c
#include <stdio.h>
using namespace std;

char maze[30][100];
int row;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void DFS(int x, int y){
	maze[x][y] = '#';

	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(maze[nx][ny] == ' ' && nx >=0 && ny >=0 && nx < row)
			DFS(nx,ny);
	}
	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q784.in", "r", stdin);
	freopen("q784.out", "w", stdout);
	#endif

	int caseNum, starX, starY;
	scanf("%d", &caseNum);
	getchar();
	while(caseNum--){
		row = 0;
		while(gets(maze[row])){
			if(maze[row++][0] == '_')
				break;
		}
		bool isFound = false;
		for(int i=0;i<row && isFound == false; ++i){
			for(int j=0;maze[i][j] != '\0'; ++j)
				if(maze[i][j] == '*'){
					DFS(i,j);
					isFound = true;
					break;
				}
		}
		for(int i=0;i<row;i++){
			puts(maze[i]);
		}
	}
	return 0;
}
