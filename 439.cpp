//2012/04/01
//439.cpp
//Run time: 0.016

#include <stdio.h>
#include <string.h>
#define INF 0x1F1F1F1F
int chessboard[8][8];
int hash[255];
const int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

typedef struct nodes{ int x, y; } pos;

pos Queue[100];

int BFS_Knight(int sx, int sy, int ex, int ey){
	static int idx, i, z, nx, ny;
	static pos T;
	memset(chessboard, 0x1F1F1F1F, sizeof(chessboard));

	Queue[0].x = sx, Queue[0].y = sy;
	chessboard[sx][sy] = idx = 0;

	for(z = 0 ; z <= idx; ++z){
		T = Queue[z];
		if(T.x == ex && T.y == ey) break;
		for(i = 0; i < 8; ++i){
			nx = T.x + dx[i], ny = T.y + dy[i];
			if(0 <= nx && nx < 8 && 0 <= ny && ny < 8 && chessboard[nx][ny] == INF){
				++idx, Queue[idx].x = nx, Queue[idx].y = ny;
				chessboard[nx][ny] = chessboard[T.x][T.y] + 1;
			}
		}
	}

	return chessboard[ex][ey];
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("439.in", "r", stdin);
	freopen("439.out", "w", stdout);
	#endif

	char buff[50];
	hash['8'] = hash['h'] = 0;
	hash['7'] = hash['g'] = 1;
	hash['6'] = hash['f'] = 2;
	hash['5'] = hash['e'] = 3;
	hash['4'] = hash['d'] = 4;
	hash['3'] = hash['c'] = 5;
	hash['2'] = hash['b'] = 6;
	hash['1'] = hash['a'] = 7;

	while(gets(buff) != NULL)
		printf("To get from %c%c to %c%c takes %d knight moves.\n", buff[0], buff[1], buff[3], buff[4], BFS_Knight(hash[buff[0]], hash[buff[1]], hash[buff[3]], hash[buff[4]]));

	return 0;
}
