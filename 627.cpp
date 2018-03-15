//2012/02/24
//627.cpp
//Run time:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int route[55][55];
int top[55];
int N, M, found;
int bt[1000];
char buff[1000];


int DFS(int u, int v, int step){
	int i, edges;

	for(edges = top[u], i = 0; i < edges; ++i){
		printf("check edges,[%d/%d] from %d to %d\n", i, edges, u, route[u][i]);
		if(route[u][i] == v){
			found = step;
			return 1;
		}
		bt[step] = route[u][i];
		if(DFS(route[u][i], v, step+1) == 1)
			return 1;
	}
	return 0;
}

void backtrack(int u){
	int i;
	printf("%d", u);
	for(i=0; i<found; ++i)
		printf(" %d", bt[i]);
	putchar(10);
}

void solve(int from, int to){
	found = 0;
	if( DFS(from, to, 0) == -1)
		puts("connection impossible");
	else
		backtrack(from);
	return;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("627.in", "r", stdin);
	freopen("627.out", "w", stdout);
	#endif

	char *token;
	int node, i, u, v;
	while(scanf("%d", &N) != EOF){
		getchar();
		memset(top, 0, sizeof(int)*N +2);
		for(i=0; i<N; ++i){
			gets(buff);
			token = strtok(buff, ",-");
			node = atoi(token);
			token = strtok(NULL, ",-");
			while(token != NULL){
				route[node][top[node]++] = atoi(token);
				token = strtok(NULL, ",-");
			}
		}
		scanf("%d", &M);
		puts("-----");
		for(i=0; i<M; ++i){
			scanf("%d%d", &u, &v);
			solve(u, v);
		}
	}

	return 0;
}
