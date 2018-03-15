//2012/03/14
//11377.cpp
//Run time: 0.044

#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_N 2005
using namespace std;

int edges[MAX_N][MAX_N];
int top[MAX_N];
int airport[MAX_N];
int visit[MAX_N];
int N, M, K, Q, caseNum;

typedef struct nodes{
	int x, cost;

	nodes(int nx, int ncost){
		x = nx;
		cost = ncost;
	}

} citys;

bool operator<(const citys &a, const citys &b) {
	return b.cost < a.cost;
}

int BFS(int from, int to){
	if(from == to)	return 0;

	static int i, u, v, c, limit;

	memset(visit, 0, sizeof(int) * (N + 2));
	priority_queue<citys> Q;
	citys tmp(from, airport[from] == 0);
	Q.push(tmp);
	visit[from] = 1;

	while(!Q.empty()){
		tmp = Q.top();	Q.pop();

		if(tmp.x == to)	return tmp.cost;

		u = tmp.x, c = tmp.cost;
		limit = top[tmp.x];
		for(i=0; i<limit; ++i){
			v = edges[u][i];
			if(!visit[v])
				Q.push(citys(v, c + (airport[v] == 0) )), visit[v] = 1;
		}
	}
	return -1;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("11377.in", "r", stdin);
	freopen("11377.out", "w", stdout);
	#endif

	int testCase, temp, u, v, query;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d%d%d", &N, &M, &K);

		while(K--)
			scanf("%d", &temp), airport[temp] = 1;

		while(M--)
			scanf("%d%d", &u, &v), edges[u][top[u]++] = v, edges[v][top[v]++] = u;

		printf("Case %d:\n", ++caseNum);
		scanf("%d", &query);

		while(query--){
			scanf("%d%d", &u, &v);
			printf("%d\n", BFS(u, v));
		}

		memset(top, 0, sizeof(int) * (N + 2) );
		memset(airport, 0, sizeof(int) * (N + 2) );

		putchar(10);
	}
	return 0;
}
