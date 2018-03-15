//q11244.cpp - 2011/10/18
//accepted at 
//run time = 0.008
#include <stdio.h>

int row, col;
char field[105][105] = {};
int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1};

inline bool DFS(int x, int y){
	field[x][y] = 46;

	bool isFound = false;
	for(int z=0;z<8;z++){
		int nx = x + dx[z];
		int ny = y + dy[z];

		if(nx >= 0 && ny >= 0 && nx < row && ny < col && field[nx][ny] == 42){
			DFS( nx, ny );
			isFound = true;
		}
	}

	if(isFound==false){
		return true;
	}else{
		return false;
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11244.in", "r", stdin);
	freopen("q11244.out", "w", stdout);
	#endif


	while(scanf("%d%d", &row, &col)!=EOF && row + col > 0){
		getchar();
		int counter = 0;
		for(int i=0;i<row;i++){
			gets(field[i]);
		}

		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){

				if( field[i][j] == 42 ){
					if(DFS(i,j)==true){
						counter++;
					}
				}
			}
		}
		printf("%d\n", counter);

	}
	return 0;
}
