//2012/03/17
//10000.cpp
//Run time:	0.028

#include <stdio.h>
#include <string.h>

int Used[105];
int Edges[105][105], Top[105];
int Len[105];
int Queue[10001], idx;
int N, caseNum;

void dijkstra(int start){
	static int i, z, limit, ans, finish, next, T;

	ans = 0, finish = start;
	idx = -1;
	Queue[++idx] = start, Used[start] = 1;

	for(i=0; i<=idx; ++i){
		T = Queue[i];
		Used[T] = 0;
		limit = Top[T];
		for(z=0; z<limit; ++z){
			next = Edges[T][z];
			if(Len[T] +1 > Len[next]){
				Len[next] = Len[T] +1;
				if(Used[next] == 0)
					Queue[++idx] = next, Used[next] = 1;
			}
		}
	}

	for(i=1; i <= N; ++i){
		if(Len[i] > ans)
			ans = Len[i], finish = i;
	}

	printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++caseNum, start, ans, finish);
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("10000.in", "r", stdin);
	freopen("10000.out", "w", stdout);
	#endif

	int st, u, v;
	while(scanf("%d", &N) == 1){
		if(N == 0)	break;
		scanf("%d", &st);
		while(1){
			scanf("%d%d", &u, &v);
			if(u + v == 0)	break;
			Edges[u][Top[u]++] = v;
		}

		dijkstra(st);
		memset(Len, 0, sizeof(int) * (N + 2) );
		memset(Used, 0, sizeof(int) * (N + 2) );
		memset(Top, 0, sizeof(int) * (N + 2) );
	}

	return 0;
}
