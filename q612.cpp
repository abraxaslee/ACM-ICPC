//q612.cpp - 2011/12/25
//accepted at 
//run time = 0.124
#include <stdio.h>

char DNA[100][55];
int disorder[100];
int output[100];

void quicksort( int start, int end, int array[], int cmp[])
{
   if( start < end )
   {
       int piv = start;
       int i;
       int temp;
       for( i = start+1 ; i < end ; i++ )
           if( cmp[array[i]] < cmp[array[start]] )
           {
               piv++;

               temp = array[i];
               array[i] = array[piv];
               array[piv] = temp;
           }else if( cmp[array[i]] == cmp[array[start]] && array[i] < array[start]){
        	   piv++;

        	   temp = array[i];
        	   array[i] = array[piv];
        	   array[piv] = temp;
           }

       temp = array[start];
       array[start] = array[piv];
       array[piv] = temp;

       quicksort( start, piv, array, cmp );
       quicksort( piv+1, end, array, cmp );
   }
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q612.in", "r", stdin);
	freopen("q612.out", "w", stdout);
	#endif

	int caseNum, n, m, i, j, z, once = 0;
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d%d", &n, &m);
		getchar();

		for(i=0; i<m; ++i){
			gets(DNA[i]);
			disorder[i] = 0;
			output[i] = i;
		}

		for(z=0; z<m; ++z)
			for(i=0; i<n; ++i)
				for(j=i+1; j<n; ++j)
					if(DNA[z][i] > DNA[z][j])
						disorder[z]++;

		quicksort(0, m, output, disorder);
		if(once)		putchar(10);

		for(i=0; i<m; ++i)
			puts(DNA[output[i]]);

		once = 1;
	}

	return 0;
}
