//2012/03/23
//820.cpp
//Run time: 0.020

#include <stdio.h>
#include <string.h>
#define INF (1 << 18)

int Used[105], d[105], prev[105], exist[105];
int width[105][105];
int Queue[10001], idx;
int N, caseNum;

int network(int Start, int End){
	static int i, z, T, Limit, Flow, MaxFlow;

	MaxFlow = 0;
	while(1){
		memset(Used, 0, sizeof(int) * (N + 2) );
		memset(d, 0, sizeof(int) * (N + 2) );
		d[Start] = INF;
		idx = 0, Queue[0] = Start, prev[Start] = Start;

		for(i = 0 ; i <= idx; ++i){
			T = Queue[i];
			Used[T] = 0;

			for(z = 1; z <= N; ++z){
				if(exist[z] == 0) continue;
				Flow = (d[T] < width[T][z]) ? d[T] : width[T][z];

				if(Flow > d[z]){
					d[z] = Flow, prev[z] = T;
					if(Used[z] == 0)	Queue[++idx] = z, Used[z] = 1;
				}
			}

		}

		if(d[End] == 0)	break;
		MaxFlow += d[End];
		T = d[End];
		for(z = End; z != Start; z = prev[z])
			width[prev[z]][z] -= T, width[z][prev[z]] += T;
	}

	return MaxFlow;
}

int main(){

	int s, t, c, u, v, w;

	while(scanf("%d", &N) == 1){
		if(N == 0)	break;
		scanf("%d%d%d", &s, &t, &c);
		while(c--){
			scanf("%d%d%d", &u, &v, &w);
			width[u][v] += w;
			width[v][u] += w;
			exist[u] = exist[v] = 1;
		}

		printf("Network %d\nThe bandwidth is %d.\n\n", ++caseNum, network(s, t));
		memset(width, 0, sizeof(width) );
		memset(exist, 0, sizeof(int) * (N +2));
	}
	return 0;
}
