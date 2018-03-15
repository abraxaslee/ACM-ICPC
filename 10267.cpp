//2012/01/21
//10267.cpp
//Run time: 0.036

#include <stdio.h>
#include <string.h>

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int row, col;
char grid[250][251];
char command[1000], filename[1000], color[5];
char* cmd = &command[2];
char org;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void DFS(int x, int y, char color){
	grid[y][x] = color;

	int nx, ny, i;
	for(i=0; i<4; ++i){
		nx = x + dx[i];
		ny = y + dy[i];
		if(0 <= nx & nx < col & 0 <= ny & ny < row)
			if(grid[ny][nx] == org)
				DFS(nx, ny, color);
	}
}




int main(){

	#ifndef ONLINE_JUDGE
	freopen("10267.in", "r", stdin);
	freopen("10267.out", "w", stdout);
	#endif

	int i, j, sx, sy, ex, ey;
	while(gets(command) != NULL){
		if(command[0] == 'X' & command[1] == '\0')	break;
		switch(command[0]){
			case 'I':
			sscanf(cmd, "%d%d", &col, &row);
			case 'C':
				for(i=0; i<row; grid[i++][col] = '\0')
					memset(grid[i] , 'O', col);
			break;

			case 'L':
				sscanf(cmd, "%d%d%s", &sx, &sy, color);
				grid[sy-1][sx-1] = color[0];
			break;

			case 'V':
				sscanf(cmd, "%d%d%d%s", &sx, &sy, &ey, color);
				if(ey < sy) swap(&sy, &ey);
				--sx;
				for(i=sy-1; i<ey; ++i)
					grid[i][sx] = color[0];
			break;

			case 'H':
				sscanf(cmd, "%d%d%d%s", &sx, &ex, &sy, color);
				if(ex < sx) swap(&sx, &ex);
				--sy;
				for(i=sx-1; i<ex; ++i)
					grid[sy][i] = color[0];
			break;

			case 'K':
				sscanf(cmd, "%d%d%d%d%s", &sx, &sy, &ex, &ey, color);
				if(ex < sx) swap(&sx, &ex);
				if(ey < sy) swap(&sy, &ey);
				for(j=sy-1; j<ey; ++j)
					for(i=sx-1; i<ex; ++i)
						grid[j][i] = color[0];
			break;

			case 'F':
				sscanf(cmd, "%d%d%s", &sx, &sy, color);
				if(0 < sx & sx <= col & 0 < sy & sy <= row)
					if(grid[sy-1][sx-1] != color[0]){
						org = grid[sy-1][sx-1];
						DFS(sx-1, sy-1, color[0]);
					}
			break;

			case 'S':
				sscanf(cmd, "%s", filename);
				puts(filename);
				for(i=0; i<row; ++i)
					puts(grid[i]);
			default:
			break;
		}
	}

	return 0;
}
