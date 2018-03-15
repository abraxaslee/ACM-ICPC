//2012/02/21
//11710.cpp
//Run time: 0.720

#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <string.h>
using namespace std;
struct EDGES{ int u, v, cost; } es[79800];
const int szof = sizeof(EDGES);
int rank[400], par[400];
int V, E;

int cmp(const void *i, const void *j){
	return (*(EDGES *)i).cost - (*(EDGES *)j).cost;
}

int find_union(int x){
	if(par[x] == x)
		return x;
	return par[x] = find_union(par[x]);
}

void unite_union(int x, int y){
	if(rank[x] < rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
	return;
}

int Kruskal(){
	if(E < V-1)	return -1;
	qsort(es, E, szof, cmp);
	memset(rank, 0, sizeof(int)*V);
	int i, set, res, x, y, MST;
	MST = V-1;
	for(res=set=i=0; i<E & set<MST; ++i){
		x = find_union(es[i].u);
		y = find_union(es[i].v);
		if(x != y){
			unite_union(x, y);
			res += es[i].cost;
			++set;
		}
	}
	if(set == V-1)	return res;
	return -1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11710.in", "r", stdin);
	freopen("11710.out", "w", stdout);
	#endif

	int ans, i, temp;
	char buff[15], from[15], to[15];
	while(scanf("%d%d", &V, &E)==2){
		if(V + E == 0) break;
		getchar();
		map<string, int> station;
		for(i=0; i<V; ++i){
			par[i] = i;
			gets(buff);
			station.insert(pair<string, int>(buff, station.size()));
		}
		for(i=0; i<E; ++i){
			scanf("%s%s%d", from, to, &es[i].cost);
			es[i].u = station[from];
			es[i].v = station[to];
		}
		scanf("%*s");

		ans = Kruskal();
		if(ans < 0)
			puts("Impossible");
		else
			printf("%d\n", ans);
	}

	return 0;
}
