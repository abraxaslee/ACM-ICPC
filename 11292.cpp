//2012/02/22
//11292.cpp
//Run time: 0.020

#include <stdio.h>
#include <stdlib.h>
int heads[20005], knights[20005];
int H, K;

void quicksort( int start, int end, int array[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; i++ )
            if( array[i] < array[start] )
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

int solve(){
	if( H > K ) return -1;
	quicksort(0, H, heads);
	quicksort(0, K, knights);
	int res, h, k;
	for(res=h=k=0; h<H & k<K; ++k)
		if(knights[k] >= heads[h]){
			res += knights[k];
			++h;
		}
	if(h == H)	return res;
	return -1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11292.in", "r", stdin);
	freopen("11292.out", "w", stdout);
	#endif

	int i, ans;
	while(scanf("%d%d", &H, &K) == 2){
		if(H + K == 0)	break;

		for(i=0; i<H; ++i)
			scanf("%d", &heads[i]);
		for(i=0; i<K; ++i)
			scanf("%d", &knights[i]);

		ans = solve();
		if(ans < 0)
			puts("Loowater is doomed!");
		else
			printf("%d\n", ans);
	}

	return 0;
}
