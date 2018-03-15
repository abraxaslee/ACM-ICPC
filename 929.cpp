//2012/02/28
//929.cpp
//Run time: 1.244

#include <cstdio>
#include <queue>
#define MAX 1005
#define INF 2147483640

using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int maze[MAX][MAX];
int cost[MAX][MAX];
int row, col;

struct nodes{
	int x, y, cost;

	nodes(int nx, int ny, int ncost){
		x = nx;
		y = ny;
		cost = ncost;
	}

};

bool operator<(const nodes &a, const nodes &b) {
	return b.cost < a.cost;
}

int dijkstra(){
	priority_queue<nodes> Q;

	int i, nx, ny, ex, ey;

	nodes t(0, 0, maze[0][0]);
	cost[0][0] = maze[0][0];
	Q.push(t);

	ex = row - 1; ey = col - 1;
	while(!Q.empty()){
		t = Q.top();	Q.pop();

		if(t.x == ex && t.y == ey)	return t.cost;
		for(i=0; i<4; ++i){
			nx = t.x + dx[i]; ny = t.y + dy[i];
			if(0 <= nx && 0 <= ny && nx < row && ny < col)
				if(cost[t.x][t.y] + maze[nx][ny] < cost[nx][ny]){
					cost[nx][ny] = cost[t.x][t.y] + maze[nx][ny];
					Q.push(nodes(nx, ny, cost[nx][ny]));
				}
		}
	}

	return cost[ex][ey];
}

int main(){


	#ifndef ONLINE_JUDGE
	freopen("929.in", "r", stdin);
	freopen("929.out", "w", stdout);
	#endif


	int testCase, i, k;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d%d", &row, &col);
		for(i=0; i<row; ++i)
			for(k=0; k<col; ++k){
				scanf("%d", &maze[i][k]);
				cost[i][k] = INF;
			}

		printf("%d\n", dijkstra());
	}
	return 0;
}
