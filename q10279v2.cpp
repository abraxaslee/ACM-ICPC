//q10279v2.cpp - 2011/12/23
//accepted at 
//run time = 0.008
#include <stdio.h>

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1};

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10279.in", "r", stdin);
	freopen("q10279.out", "w", stdout);
	#endif

	int caseNum, i, j, z, nx, ny, once = 0, size;
	char buffer[15];
	char map[15][15];
	scanf("%d", &caseNum); getchar();
	while(caseNum--){
		int fail = 0;
		int bomb[10][10] = {};

		getchar();
		scanf("%d", &size);	getchar();

		for(i=0; i<size; ++i){
			gets(buffer);
			for(j=0; j<size; ++j)
				if(buffer[j] == '*')
					bomb[i][j] = 1;
		}

		if(once)		putchar(10);

		for(i=0; i<size; ++i){
			gets(buffer);
			for(j=0; j<size; ++j){
				if(buffer[j] == 'x'){
					if(bomb[i][j]){
						fail = 1;
					}else{
						map[i][j] = '0';
						for(z=0; z<8; ++z){
							ny = i + dy[z];
							nx = j + dx[z];
							if(0 <= ny && ny < size && 0 <= nx && nx <size)
								if(bomb[ny][nx])
									map[i][j]++;
						}
					}
				}else
					map[i][j] = '.';
			}
			map[i][j] = '\0';
		}

		if(fail){
			for(i=0; i<size; ++i){
				for(j=0; j<size; ++j)
					if(bomb[i][j])
						map[i][j] = '*';
				puts(map[i]);
			}
		}else
			for(i=0; i<size; ++i)
					puts(map[i]);

		once = 1;
	}

	return 0;
}

