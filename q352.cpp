//q352.cpp - 2011/11/17
//accepted at 
//run time = 0.004 c
#include <stdio.h>

char WARZONE[30][30];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
int dimension;

inline void DFS(int x, int y){
	WARZONE[x][y] = '0';

	int i;
	for(i=0;i<8;++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if( nx >= 0 && ny >= 0 && nx < dimension && ny < dimension)
			if(WARZONE[nx][ny] == '1')
				DFS( nx, ny);
	}
	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q352.in", "r", stdin);
	freopen("q352.out", "w", stdout);
	#endif

	int i, j, eagles, currentCase = 0;
	while(scanf("%d", &dimension)!=EOF){

		getchar();
		for(i=0;i<dimension;++i)
			gets(WARZONE[i]);

		eagles = 0;

		for(i=0;i<dimension;++i)
			for(j=0;j<dimension;++j){
				if(WARZONE[i][j] == '1'){
					++eagles;
					DFS( i, j);
				}
			}

		printf("Image number %d contains %d war eagles.\n", ++currentCase, eagles);
	}
	return 0;
}
