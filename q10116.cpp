//q10116.cpp - 2011/11/21
//accepted at 
//run time = 0.016
#include <stdio.h>

char map[15][15];
int row, col, entry, step;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int hash[255];

int min(int A, int B){
	return A<B ? A : B;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10116.in", "r", stdin);
	freopen("q10116.out", "w", stdout);
	#endif

	hash[78] = 0; hash[69] = 1; hash[83] = 2; hash[87] = 3;
	while(scanf("%d%d%d\n", &row, &col, &entry)!=EOF && row + col + entry > 0){

		int path[15][15] = {};
		step = 1;
		int x = 0, y = entry - 1, next, i, before, print = 0;

		for(i=0;i<row;i++)
			gets(map[i]);

		while( 0 <= x && 0 <= y && x < row && y <col){

			if(path[x][y] != 0){
				printf("%d step(s) before a loop of %d step(s)\n", path[x][y]-1, step - path[x][y]);
				print = 1;
				break;
			}

			next = (int)map[x][y];
			path[x][y] = step++;
			x += dx[hash[next]];
			y += dy[hash[next]];
		}
		if(print == 0)
			printf("%d step(s) to exit\n", step-1);
	}
	return 0;
}
