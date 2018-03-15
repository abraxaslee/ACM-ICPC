//q11364.cpp - 2012/01/06
//accepted at 
//run time = 0.004
#include <stdio.h>

int street[20];

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
	freopen("q11364.in", "r", stdin);
	freopen("q11364.out", "w", stdout);
	#endif

	int caseNum, top, i;
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d", &top);
		for(i=0; i<top; ++i)
			scanf("%d", &street[i]);
		if(top > 1)
			quicksort(0, top, street);
		printf("%d\n", (street[top-1] - street[0])*2);
	}
	return 0;
}
