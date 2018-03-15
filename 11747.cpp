//2012/02/12
//11747.cpp
//Run time: 0.008

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct EDGES{ int u, v, w; } es[25005], *a, *b;
int rank[1005], par[1005];
int V, E, said;

int cmp(const void *i, const void *j){
	a = (EDGES *)i, b = (EDGES *) j;
	return a->w - b->w;
}

int find_union(int x){
	if(par[x] == x)
		return x;
	return par[x] = find_union(par[x]);
}


void kruskul(){
	qsort(es, E, sizeof(EDGES), cmp);
	memset(rank, 0, sizeof(int)*V);
	int i, set, x, y;
	for(said=set=i=0; i<E ; ++i){
		x = find_union(es[i].u);
		y = find_union(es[i].v);
		if(x != y){
			if(rank[x] < rank[y]){
					par[x] = y;
			}else{
				par[y] = x;
				if(rank[x] == rank[y]) rank[x]++;
			}
			++set;
		}else{
			printf("%d", es[i].w);
			said = 1;
			break;
		}
	}

	for(i=i+1; i<E; ++i){
			x = find_union(es[i].u);
			y = find_union(es[i].v);
			if(x != y){
				if(rank[x] < rank[y]){
						par[x] = y;
				}else{
					par[y] = x;
					if(rank[x] == rank[y]) rank[x]++;
				}
				++set;
			}else{
				printf(" %d", es[i].w);
			}
		}
	if(said)
		putchar(10);
	else
		puts("forest");
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11747.in", "r", stdin);
	freopen("11747.out", "w", stdout);
	#endif

	int i;
	while( scanf("%d%d", &V, &E) != EOF){
		if( V + E == 0)	break;
		for(i=0; i<V; ++i)
			par[i] = i;
		for(i=0; i<E; ++i)
			scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);

		kruskul();
	}
	return 0;
}
