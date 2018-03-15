//q10041.cpp - 2011/11/14
//accepted at 
//run time = 
#include <stdio.h>

int abs(int A, int B){
	return (A>B)? A-B : B-A;
}

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

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10041.in", "r", stdin);
	freopen("q10041.out", "w", stdout);
	#endif

	int caseNum, relatives, houseTmp, median, result, i;
	scanf("%d", &caseNum);
	while(caseNum--){
		int homies[505] = {};
		scanf("%d", &relatives);

		for(i=0;i<relatives;++i)
			scanf("%d", &homies[i]);

		quicksort( 0 , relatives, homies );
		if(relatives & 1)
			median = homies[relatives/2];
		else
			median = (homies[(relatives-1)/2 +1] + homies[(relatives-1)/2])/2;

		result = 0;
		for(i=0;i<relatives;++i)
			result += abs(median, homies[i]);
		printf("%d\n", result);
	}
	return 0;
}
