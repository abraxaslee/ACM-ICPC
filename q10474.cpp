//q10474.cpp - 2011/11/13
//accepted at 
//run time = 0.928 / 0.952 c
#include <stdio.h>

int marble[100000];
int marbleNum, queryNum, caseNum = 0;

inline int binarySearch(int search){
	int low = 0, high = marbleNum -1;
	int mid;

	while(low <= high){

		mid = (low + high)/2;

		if(marble[mid] == search)
			return mid;
		else if(search > marble[mid])
			low = mid + 1;
		else if(marble[mid] > search)
			high = mid - 1;

	}

	return -1;
}

inline void quicksort( int start, int end, int array[] )
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

inline int trace(int target, int place){

	while(marble[place] == target)
		--place;

	return ++place;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10474.in", "r", stdin);
	freopen("q10474.out", "w", stdout);
	#endif

	while(scanf("%d %d", &marbleNum, &queryNum)!= EOF && marbleNum > 0 && queryNum > 0){

		int i, query, bResult;

		for(i=0;i<marbleNum;++i)
			scanf("%d", &marble[i]);

		quicksort( 0, marbleNum, marble);

		printf("CASE# %d:\n", ++caseNum);

		for(i=0;i<queryNum;++i){
			scanf("%d", &query);
			bResult = binarySearch(query);

			if(bResult == -1)
				printf("%d not found\n", query);
			else{
				printf("%d found at %d\n", query, trace(query, bResult)+1);
			}
		}

	}
	return 0;
}
