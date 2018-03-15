//2012/02/12
//11631.cpp
//Run time: 0.440

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct EDGES{ int u, v, d; } es[200005], *a, *b;
int rank[200005], par[200005];
int V, E;

int cmp(const void *i, const void *j){
	a = (EDGES *)i, b = (EDGES *) j;
	return a->d - b->d;
}

int find_union(int x){
	if(par[x] == x)
		return x;
	return par[x] = find_union(par[x]);
}


int kruskul(){
	qsort(es, E, sizeof(EDGES), cmp);
	memset(rank, 0, sizeof(int)*V);
	int i, set, result, x, y;
	for(result=set=i=0; i<E & set<V; ++i){
		x = find_union(es[i].u);
		y = find_union(es[i].v);
		if(x != y){
			if(rank[x] < rank[y]){
					par[x] = y;
			}else{
				par[y] = x;
				if(rank[x] == rank[y]) rank[x]++;
			}
			result += es[i].d;
			++set;
		}
	}
	return result;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("11631.in", "r", stdin);
	freopen("11631.out", "w", stdout);
	#endif

	int i, org;
	while( scanf("%d%d", &V, &E) != EOF){
		if( V == 0 && E == 0) break;
		for(org=i=0; i<E; ++i){
			par[i] = i;
			scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].d);
			org += es[i].d;
		}
		if(E == V-1)
			puts("0");
		else
			printf("%d\n", org - kruskul());
	}
	return 0;
}
