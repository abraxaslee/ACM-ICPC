//q11371.cpp - 2011/11/11
//accepted at 
//run time = 0.008
#include <stdio.h>
inline void bigquicksort( int start, int end, char array[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        char temp;
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

        bigquicksort( start, piv, array );
        bigquicksort( piv+1, end, array );
    }
}

inline void quicksort( int start, int end, char array[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        char temp;
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
	freopen("q11371.in", "r", stdin);
	freopen("q11371.out", "w", stdout);
	#endif

	char big[15], small[15] = {};
	int i, j;
	double bigNum, smallNum, diff;
	while(gets(big)!=NULL){

		for(i=0;big[i]!='\0';++i)
			small[i] = big[i];

		small[i] = '\0';
		bigquicksort( 0 , i, big);
		quicksort( 0 , i, small);

		j=1;
		char temp;
		if(small[0]=='0'){
			while(small[j]=='0')
				j++;
			temp = small[j];
			small[j] = small[0];
			small[0] = temp;
		}
		sscanf(big, "%lf", &bigNum);
		sscanf(small, "%lf", &smallNum);
		diff = bigNum - smallNum;
		printf("%s - %s = %.0lf = 9 * %.0lf\n", big , small, diff, diff/9);
	}
	return 0;
}
