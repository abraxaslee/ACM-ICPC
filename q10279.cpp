//q10279.cpp - 2011/12/18
//accepted at 
//run time = 0.044
#include <stdio.h>

char grid[10][15];
int bomb[10][10];

int size;
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1};

void clear(){
	int i, j;
	for(i=0; i<10; ++i)
		for(j=0; j<10; ++j){
			grid[i][j] = '0';		bomb[i][j] = 0;
		}
	return;
}
void add(int x, int y){
	int i;
	for(i=0;i<8;++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if( 0 <= nx && nx < size && 0 <= ny && ny < size)
			grid[ny][nx] += 1;
	}
	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10279.in", "r", stdin);
	freopen("q10279.out", "w", stdout);
	#endif

	int caseNum, i, j, c, once = 0;
	scanf("%d", &caseNum); getchar();
	while(caseNum--){
		clear();
		getchar();
		scanf("%d", &size); getchar();
		int fail = 0;

		for(i=0; i<size; ++i){
			for(j=0; j<size; ++j){
				c = getchar();
				if(c == '*'){
					add(j,i);
					bomb[i][j] = 1;
				}
			}
			getchar();
			grid[i][j] = '\0';
		}

		for(i=0; i<size; ++i){
			for(j=0; j<size; ++j){
				c = getchar();
				if(c == '.')
					grid[i][j] = '.';
				if(bomb[i][j] && c == 'x')
					fail = 1;
			}
			getchar();
		}

		if(once)	putchar(10);

		if(fail){
			for(i=0; i<size; ++i)
				for(j=0; j<size; ++j)
					if(bomb[i][j])
						grid[i][j] = '*';
		}
		for(i=0;i<size; ++i)
			puts(grid[i]);

		once = 1;
	}

	return 0;
}
