//q195.cpp - 2011/10/31
//accepted at 
//run time = 0.012
#include <stdio.h>
#include <string.h>

int index[300];
int length;
char buffer[1000];

int cmp(char a, char b){
	return (index[a] < index[b]);
}

void buildIndex(){
	int j = 65, i;
	for(i=0;i<52;i+=2){
		index[j++] = i;
	}
	j = 97;
	for(i=1;i<52;i+=2){
		index[j++] = i;
	}
	return;
}

void quicksort( int start, int end, char array[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        char temp;
        for( i = start+1 ; i < end ; i++ )
            if( cmp(array[i], array[start]) )
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
    return;
}

void charswap(int i, int j)
{
     char tmp;
     tmp = buffer[i];
     buffer[i] = buffer[j];
     buffer[j] = tmp;
}

int next_permutation()
{
    int i, j, k;
    for(i = length - 1;i > 0 ; --i)
        if(cmp(buffer[i-1], buffer[i])) break;
    j = i;
    if(j == 0) return 0;
    for(i = length - 1;i > 0; --i)
        if(cmp(buffer[j-1], buffer[i])) break;
    k = i;
    charswap(j-1, k);
    for(i = j, j = length - 1;i < j; ++i, --j)
        charswap(i, j);
    return 1;
}

int main(){

	int caseNum;
	scanf("%d", &caseNum); getchar();
	buildIndex();
	while(caseNum--){
		gets(buffer);
		length = strlen(buffer);
		quicksort(0, length, buffer);
		do{
			puts(buffer);
		}while(next_permutation());
	}

	return 0;
}
