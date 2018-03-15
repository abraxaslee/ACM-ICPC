//2012/01/17
//10004.cpp
//Run time: 0.008

#include <stdio.h>
#include <string.h>

int G[200][200];
int top[200];
int color[200];
int V, E;


int DFS(int v, int c){
	color[v] = c;
	int i;
	for(i=0 ; i<top[v]; ++i){
		if(color[G[v][i]] == c)	return 0;
		if(color[G[v][i]] == 0 && !DFS(G[v][i], -c)) return 0;
	}
	return 1;
}

int main(){

	int i, s, t;
	while(scanf("%d%d", &V, &E) == 2){
		for(i = 0; i < E; ++i){
			scanf("%d%d", &s, &t);
			G[s][top[s]++] = t;
			G[t][top[t]++] = s;
		}

		for(i=0; i<V; ++i)
			if(color[i] == 0)
				if(!DFS(i, 1))
					break;

		if(i == V)
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");

		memset(top, 0, sizeof(int)*V +1);
		memset(color, 0, sizeof(int)*V +1);
	}

	return 0;
}
