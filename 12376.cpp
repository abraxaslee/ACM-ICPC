//2012/02/17
//12376.cpp
//Run time: 0.056

#include <stdio.h>
#include <string.h>
int node[110];
int edge[110][100];
int top[110];
int ans, caseNum, final, V, E;

void quicksort( int start, int end, int array[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; i++ )
            if( node[array[i]] > node[array[start]] )
            {
                piv++;

                temp = array[i];
                array[i] = array[piv];
                array[piv] = temp;
            }

        temp = array[start];
        array[start] = array[piv];
        array[piv] = temp;

        quicksort( start, piv, array );
        quicksort( piv+1, end, array );
    }
}

void solve(){
	final = 0;
	ans = node[0];
	while(top[final]){
		quicksort(0, top[final], edge[final]);
		final = edge[final][0];
		ans += node[final];
	}
	printf("Case %d: %d %d\n", ++caseNum, ans, final);
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("12376.in", "r", stdin);
	freopen("12376.out", "w", stdout);
	#endif

	int testCase, i, temp;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d%d", &V, &E);
		for(i=0; i<V; ++i)
			scanf("%d", &node[i]);
		for(i=0; i<E; ++i){
			scanf("%d", &temp);
			scanf("%d", &edge[temp][top[temp]++]);
		}
		solve();
		if(testCase)
			memset(top, 0, sizeof(int)*V);
	}
	return 0;
}
