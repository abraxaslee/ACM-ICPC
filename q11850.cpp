//q11850.cpp - 2011/12/10
//accepted at 
//run time = 0.004
#include <stdio.h>

int station[1425];

void quicksort( int start, int end, int array[] ){
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

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11850.in", "r", stdin);
	freopen("q11850.out", "w", stdout);
	#endif

	int top, i, possible;
	while(scanf("%d", &top)!=EOF){
		if(top == 0) break;

		for(i=0; i<top; ++i)
			scanf("%d", &station[i]);

		quicksort(0, top, station);

		possible = 1;
		for(i=1; i<top; ++i)
			if(station[i] - station[i-1] > 200){
				possible = 0;
				break;
			}

		if(2 * (1422 - station[top-1]) > 200)
			possible = 0;

		if(possible)
			puts("POSSIBLE");
		else
			puts("IMPOSSIBLE");

	}
	return 0;
}
