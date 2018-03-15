//2012/02/11
//908.cpp
//Run time: 0.008

#include <stdio.h>
#include <string.h>
struct EDGES { int u, v, cost; } es[1000015], temp;
int rank[1000005], par[1000005];
int V, E, once;

void quicksort( int start, int end )
{
    if( start < end )
    {
        int piv = start;
        int i;
        for( i = start+1 ; i < end ; i++ )
            if( es[i].cost < es[start].cost )
            {
                piv++;

                temp = es[i];
                es[i] = es[piv];
                es[piv] = temp;
            }

        temp = es[start];
        es[start] = es[piv];
        es[piv] = temp;

        quicksort( start, piv );
        quicksort( piv+1, end );
    }
}

void init_union(){
	int i;
	for(i=1; i<=V; ++i)
		par[i] = i;
	memset(rank, 0, sizeof(int)*V+1);
	return;
}

int find_union(int x){
	if(par[x] == x)
		return x;
	return par[x] = find_union(par[x]);
}

void unite_union(int x, int y){
	x = find_union(x);
	y = find_union(y);
	if(x == y)	return;

	if(rank[x] < rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
	return;
}

int same(int x, int y){
	return find_union(x) == find_union(y);
}

int kruskul(){
	quicksort(0, E);
	init_union();
	int i, set, result;
	for(result=set=i=0; i<E & set<V; ++i){
		temp = es[i];
		if(!same(temp.u, temp.v)){
			unite_union(temp.u, temp.v);
			result += temp.cost;
			++set;
		}
	}
	return result;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("908.in", "r", stdin);
	freopen("908.out", "w", stdout);
	#endif

	int i, k, discard, org;
	while( scanf("%d", &V) != EOF ){

		for(org=i=0, k=V-1; i<k; ++i){
			scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].cost);
			org += es[i].cost;
		}

		scanf("%d", &k);
		E = V + k -1;
		for(; i<E; ++i)
			scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].cost);

		scanf("%d", &discard);
		for(i=0; i<discard; ++i)
			scanf("%*d%*d%*d");

		if(once)  putchar(10);
		printf("%d\n%d\n", org, kruskul());
		once = 1;

	}
	return 0;
}
