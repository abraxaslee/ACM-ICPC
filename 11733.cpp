//2012/03/06
//11733.cpp
//Run time:

#include <stdio.h>
#include <string.h>
#define MAX_V 10020
#define MAX_E 100005

typedef struct EDGES{ int u, v, cost; } edges;
edges roads[MAX_E], temp;
int par[MAX_V], rank[MAX_V];
int V, E, TOP, SET, Airport, caseNum;

void quicksort( int start, int end )
{
    if( start < end )
    {
        int piv = start;
        int i;
        for( i = start+1 ; i < end ; i++ )
            if( roads[i].cost < roads[start].cost )
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

void kruskal(){
	memset(rank, 0, sizeof(int)*V +5);
	quicksort(0, TOP);

	int i, ans, x, y;
	SET = V;

	for(ans=i=0; i<TOP & SET > 1; ++i){
		x = find_union(roads[i].u), y = find_union(roads[i].v);
		if(x != y){
			if(rank[x] < rank[y]){
					par[x] = y;
			}else{
				par[y] = x;
				if(rank[x] == rank[y]) rank[x]++;
			}
			ans += roads[i].cost;
			--SET;
		}
	}

	ans += SET * Airport;
	printf("Case #%d: %d %d\n", ++caseNum, ans, SET);
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11733.in", "r", stdin);
	freopen("11733.out", "w", stdout);
	#endif

	int testCase,i;	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d%d%d", &V, &E, &Airport);
		for(i=1; i<=V; ++i)
			par[i] = i;
		for(TOP=i=0; i<E; ++i){
			scanf("%d%d%d", &roads[TOP].u, &roads[TOP].v, &roads[TOP].cost);
			if(roads[TOP].cost < Airport) ++TOP;
		}

		kruskal();
	}
	return 0;
}
