//q11831.cpp - 2011/12/26
//accepted at 
//run time = 0.016
#include <stdio.h>

char map[100][105];
char cmd[50005];
int hash[255];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11831.in", "r", stdin);
	freopen("q11831.out", "w", stdout);
	#endif

	int N, M, S, x, y, dir, i, j;
	hash['N'] = 0, hash['L'] = 1, hash['S'] = 2, hash['O'] = 3;
	while(scanf("%d%d%d", &N, &M, &S) == 3){
		if(N+M+S == 0)		break;

		getchar();
		int ans = 0;
		for(j=0; j<N; ++j)
			gets(map[j]);

		gets(cmd);

		for(j=0; j<N; ++j)
			for(i=0; i<M; ++i)
				if(map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'L' || map[j][i] == 'O'){
					x = i,	y = j,	dir = hash[map[j][i]], map[j][i] = '.';
					break;
				}

		for(i=0; i<S; ++i){
			int nx, ny;
			switch(cmd[i]){
				case 'D':
					dir = (dir+1)%4;
					break;
				case 'E':
					if(dir == 0)
						dir = 3;
					else
						dir -= 1;
					break;
				case 'F':
					nx = x + dx[dir];
					ny = y + dy[dir];
					if( 0 <= nx && nx < M && 0 <= ny && ny < N && map[ny][nx] != '#'){
						x = nx, y = ny;
						if(map[y][x] == '*'){
							ans++;
							map[y][x] = '.';
						}
					}
					break;
			}

		}

		printf("%d\n", ans);
	}

	return 0;
}
