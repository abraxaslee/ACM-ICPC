//q11056.cpp - 2011/12/29
//accepted at 
//run time = 0.008
//sorting pilots' name (which have same "time") in lexicographically, case-insensitive comparisons
#include <stdio.h>
#include <string.h>

char pilot[100][25];
char buff[100];
int time[100];
int output[100];
int top;

void quicksort( int start, int end, int array[], int target[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; i++ )
            if( target[array[i]] < target[array[start]] )
            {
                piv++;

                temp = array[i];
                array[i] = array[piv];
                array[piv] = temp;
            }else if( target[array[i]] == target[array[start]] && strcasecmp(pilot[array[i]], pilot[array[start]]) < 0 ){
            	  piv++;

            	  temp = array[i];
            	  array[i] = array[piv];
            	  array[piv] = temp;
            }

        temp = array[start];
        array[start] = array[piv];
        array[piv] = temp;

        quicksort( start, piv, array, target );
        quicksort( piv+1, end, array, target );
    }
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11056.in", "r", stdin);
	freopen("q11056.out", "w", stdout);
	#endif

	int i, MIN, SEC, MS, row;
	while(scanf("%d", &top)!=EOF){
		getchar();
		for(i = 0; i < top; ++i){
			gets(buff);
			sscanf(buff, "%s : %d min %d sec %d", pilot[i], &MIN, &SEC, &MS);
			time[i] = ((MIN *60) + SEC) * 1000 + MS;
			output[i] = i;
		}
		quicksort(0, top, output, time);

		for(i = row = 0; i<top-1; i+=2){
			printf("Row %d\n", ++row);
			puts(pilot[output[i]]);
			puts(pilot[output[i+1]]);
		}
		if(top%2){
			printf("Row %d\n", ++row);
			puts(pilot[output[i]]);
		}
		putchar(10);
	}

	return 0;
}
