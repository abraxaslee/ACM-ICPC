//2012/02/11
//10034.cpp
//Run time: 0.004
#include <stdio.h>
#include <string.h>
#include <math.h>

struct EDGES{ int u, v;	double d; } es[5000], temp, ed;
struct FRECKLES{ double x, y; } freks[100];

int V, E, caseNum, once;
int par[100], rank[100];

double sr(double x){
	return x * x;
}

void quicksort( int start, int end)
{
    if( start < end )
    {
        int piv = start;
        int i;
        for( i = start+1 ; i < end ; i++ )
            if( es[i].d < es[start].d )
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
        quicksort( piv+1, end);
    }
}

void init_union(){
	int i;
	for(i=0; i<V; ++i)
		par[i] = i;
	memset(rank, 0, sizeof(int)*V);
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

double kruskal(){
	quicksort(0, E);
	init_union();
	double res = 0;
	int i, set;

	for(set=i=0; i<E & set<V; ++i){
		ed = es[i];
		if(!same(ed.u, ed.v)){
			unite_union(ed.u, ed.v);
			res += ed.d;
			++set;
		}
	}
	return res;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10034.in", "r", stdin);
	freopen("10034.out", "w", stdout);
	#endif

	scanf("%d", &caseNum);
	int i, j;
	while(caseNum--){
		scanf("%d", &V);

		for(i=0; i<V; ++i)
			scanf("%lf%lf", &freks[i].x, &freks[i].y);

		for(E=i=0; i<V; ++i)
			for(j=i+1; j<V; ++j){
				es[E].u = i;
				es[E].v = j;
				es[E].d = sqrt(sr((freks[i].x - freks[j].x)) + sr((freks[i].y - freks[j].y)));
				++E;
			}

		if(once)	putchar(10);
		printf("%.2f\n", kruskal());
		once = 1;
	}
	return 0;
}
