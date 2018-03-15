//q11369.cpp - 2011/11/11
//accepted at 
//run time = 0.128 / 0.124c
#include <stdio.h>

void quicksort( int start, int end, int array[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; i++ )
            if( array[i] > array[start] )
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
	freopen("q11369.in", "r", stdin);
	freopen("q11369.out", "w", stdout);
	#endif

	int caseNum, i, n, result;
	int shoplist[20005];
	scanf("%d", &caseNum);
	while(caseNum--){

		scanf("%d", &n);
		for(i=0;i<n;++i)
			scanf("%d", &shoplist[i]);

		quicksort(0, n, shoplist);
		result = 0;

		for(i=2;i<n;i+=3)
			result += shoplist[i];

		printf("%d\n", result);
	}
	return 0;
}
