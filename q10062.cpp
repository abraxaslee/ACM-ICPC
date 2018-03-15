//q10062.cpp - 2011/11/21
//accepted at 
//run time = 0.004
#include <stdio.h>

char buff[1005];
int output[300];


void quicksort( int start, int end, int array[])
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;

        for( i = start+1 ; i < end ; i++ ){
            if( array[output[i]] < array[output[start]] )
            {
                piv++;

                temp = output[i];
                output[i] = output[piv];
                output[piv] = temp;

            }else if( array[output[i]] == array[output[start]] && output[i] > output[start] ){
            	piv++;

				temp = output[i];
				output[i] = output[piv];
				output[piv] = temp;
            }
        }

        temp = output[start];
        output[start] = output[piv];
        output[piv] = temp;

        quicksort( start, piv, array );
        quicksort( piv+1, end, array );
    }
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10062.in", "r", stdin);
	freopen("q10062.out", "w", stdout);
	#endif

	int i, top, once = 0;
	while(gets(buff)!=NULL){
		int words[300] = {}; int added[300] = {};
		top = 0;
		for(i=0;buff[i]!='\0';++i){
			words[buff[i]] += 1;
			if(added[buff[i]] == 0){
				added[buff[i]] = 1;
				output[top++] = buff[i];
			}
		}
		if(once)
			putchar(10);

		quicksort(0, top, words);
		for(i=0;i<top;++i)
			printf("%d %d\n", output[i], words[output[i]]);

		once = 1;
	}
	return 0;
}
