//2012/04/01
//532.cpp
//Run time: 0.008

#include <stdio.h>
#include <string.h>
#define INF 0x1F1F1F1F

char maze[35][35][35];
int d[35][35][35];
int L, R, C;
int S, sx, sy, sl;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

typedef struct nodes{
	int L, R, C;
} pos;

pos Queue[50001];

int BFS(){
	static int idx, z, i, nL, nR, nC;
	static pos T ;
	Queue[0].L = sl , Queue[0].R = sx, Queue[0].C = sy;
	d[sl][sx][sy] = idx = 0;

	for(z=0; z<=idx; ++z){
		T = Queue[z];
		if(maze[T.L][T.R][T.C] == 'E') return d[T.L][T.R][T.C];;

		nL = T.L;
		for(i=0; i<4; ++i){
			nR = T.R + dx[i], nC = T.C + dy[i];
			if(0 <= nR && nR < R && 0 <= nC && nC < C && maze[nL][nR][nC] != '#' && d[nL][nR][nC] == INF){
				++idx, Queue[idx].L = nL, Queue[idx].R = nR, Queue[idx].C = nC;
				d[nL][nR][nC] = d[T.L][T.R][T.C] + 1;
			}
		}

		nR = T.R, nC = T.C;

		nL = T.L - 1;
		if(0 <= nL && nL < L && maze[nL][nR][nC] != '#' && d[nL][nR][nC] == INF){
			++idx, Queue[idx].L = nL, Queue[idx].R = nR, Queue[idx].C = nC;
			d[nL][nR][nC] = d[T.L][T.R][T.C] + 1;
		}

		nL = T.L + 1;
		if(0 <= nL && nL < L && maze[nL][nR][nC] != '#' && d[nL][nR][nC] == INF){
			++idx, Queue[idx].L = nL, Queue[idx].R = nR, Queue[idx].C = nC;
			d[nL][nR][nC] = d[T.L][T.R][T.C] + 1;
		}
	}
	return -1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("532.in", "r", stdin);
	freopen("532.out", "w", stdout);
	#endif

	int i, z, k, ans;



	while(scanf("%d%d%d", &L, &R, &C) == 3){
		if(L + R + C == 0) break;

		getchar();

		S = 1;

		for(i=0; i<L; ++i){
			memset(d[i], 0x1f, sizeof(d[i]));
			for(z=0; z<R; ++z){
				gets(maze[i][z]);
				for(k=0; k<C && S; ++k)
					if(maze[i][z][k] == 'S')
						sl = i, sx = z, sy = k, S = 0;
			}
			getchar();
		}
		ans = BFS();
		if(ans < 0)
			puts("Trapped!");
		else
			printf("Escaped in %d minute(s).\n", ans);

	}

	return 0;
}
