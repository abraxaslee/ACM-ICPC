//2012/03/06
//11857.cpp
//Run time: 0.648

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EDGES{ int u, v, r; } edges;
edges roads[1000000], temp;
int par[1000000], rank[1000000];
int V, E;

void quicksort( int start, int end )
{
    if( start < end )
    {
        int piv = start;
        int i;
        for( i = start+1 ; i < end ; i++ )
            if( roads[i].r < roads[start].r )
            {
                piv++;

                temp = roads[i];
                roads[i] = roads[piv];
                roads[piv] = temp;
            }

        temp = roads[start];
        roads[start] = roads[piv];
        roads[piv] = temp;

        quicksort( start, piv );
        quicksort( piv+1, end );
    }
}


int find_union(int x){
	if(par[x] == x)	return x;
	return par[x] = find_union(par[x]);
}

int max(int x, int y){
	return x > y ? x : y;
}

int kruskal(){
	if(E < V - 1)	return -1;

	quicksort(0, E);
	memset(rank, 0, sizeof(int)*V);

	int i, min_range, SET, MST, x, y;
	MST = V - 1;

	for(min_range=SET=i=0; i<E & SET < MST; ++i){
		x = find_union(roads[i].u), y = find_union(roads[i].v);
		if(x != y){

			if(rank[x] < rank[y])
				par[x] = y;
			else{
				par[y] = x;
				if(rank[x] == rank[y]) rank[x]++;
			}

			min_range = max(min_range, roads[i].r);
			++SET;
		}
	}
	if(SET == MST)	return min_range;
	return -1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11857.in", "r", stdin);
	freopen("11857.out", "w", stdout);
	#endif

	int i, ans;
	while(scanf("%d%d", &V, &E) == 2){
		if(V + E == 0)	break;

		for(i=0; i<E; ++i){
			scanf("%d%d%d", &roads[i].u, &roads[i].v, &roads[i].r);
			par[i] = i;
		}
		for(; i<V; ++i)
			par[i] = i;


		ans = kruskal();
		if(ans < 0)
			puts("IMPOSSIBLE");
		else
			printf("%d\n", ans);

	}
	return 0;
}
