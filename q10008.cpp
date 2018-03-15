//q10008.cpp - 2011/11/23
//accepted at 
//run time = 0.008
#include <stdio.h>

int output[30];
int top;

void quicksort( int start, int end, int array[])
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;

        for( i = start+1 ; i < end ; i++ ){
            if( array[output[i]] > array[output[start]] )
            {
                piv++;

                temp = output[i];
                output[i] = output[piv];
                output[piv] = temp;

            }else if( array[output[i]] == array[output[start]] && output[i] < output[start] ){
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
	freopen("q10008.in", "r", stdin);
	freopen("q10008.out", "w", stdout);
	#endif

	int words[300] = {};
	int inputLines, c, i;
	scanf("%d", &inputLines);
	getchar();
	while(inputLines){
		c = getchar();
		if(c == 10)
			inputLines -= 1;
		else
			words[c] += 1;
	}

	for(i=65;i<=90;++i){
		words[i] += words[i+32];
		if(words[i] > 0)
			output[top++] = i;
	}

	quicksort( 0, top, words);

	for(i=0;i<top;++i)
		printf("%c %d\n", output[i], words[output[i]]);

	return 0;
}
