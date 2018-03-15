//q459.cpp - 2011/12/24
//accepted at 
//run time = 0.004
#include <stdio.h>

int graph[26][26];
int visit[26];
char node[5];
int MAX;


void BFS(int n){
	visit[n] = 1;
	int i;
	for(i=0; i<MAX; ++i)
		if(!visit[i])
			if(graph[n][i] | graph[i][n])
				BFS(i);
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q459.in", "r", stdin);
	freopen("q459.out", "w", stdout);
	#endif

	int caseNum, i, j, once = 0;
	scanf("%d", &caseNum);	getchar(); 	getchar();
	while(caseNum--){
		MAX = getchar() - '@';	getchar();

		for(i=0; i<MAX; ++i){
			visit[i] = 0;
			for(j=0; j<MAX; ++j)
				graph[i][j] = 0;
		}

		for(i=0; i<MAX; ++i)
			graph[i][i] = 1;

		while(gets(node)!=NULL && node[0] != '\0')
			graph[node[0] - 'A'][node[1] - 'A'] = 1;

		int ans = 0;
		for(i=0; i<MAX; ++i)
			if(!visit[i]){
				BFS(i);
				ans++;
			}
		if(once)		putchar(10);
		printf("%d\n", ans);
		once = 1;
	}

	return 0;
}
