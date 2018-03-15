//q10905.cpp - 2011/11/10
//accepted at 
//run time = 
#include <stdio.h>
#include <stdlib.h>

char list[50][15];

void quicksort( int start, int end, int array[] )
{
    if( start < end )
    {
        int piv = start;
        int i, j;
        int temp;
        for( i = start+1 ; i < end ; ++i ){
        	for( j = 0 ; list[array[i]][j] != '\0' && list[array[start]][j] != '\0'; ++j ){
				if( list[array[i]][j] > list[array[start]][j] )
				{
					piv++;

					temp = array[i];
					array[i] = array[piv];
					array[piv] = temp;
					break;
				}
        	}
        }
        temp = array[start];
        array[start] = array[piv];
        array[piv] = temp;

        quicksort( start, piv, array );
        quicksort( piv+1, end, array );
    }
}
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10905.in", "r", stdin);
	freopen("q10905.out", "w", stdout);
	#endif

	int N, i;
	while(scanf("%d", &N)!=EOF && N > 0){
		int index[50] = {};

		for(i=0;i<N;++i){
			scanf("%s", list[i]);
			index[i] = i;
		}
		quicksort(0, N, index);
		for(i=0;i<N;++i)
			printf("%s", list[index[i]]);
		putchar(10);
	}
	return 0;
}
