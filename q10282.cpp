//q10282.cpp - 2012/01/05
//accepted at 
//run time = 0.204
#include <stdio.h>
#include <string.h>

char dict[2][100005][20];
int output[100005];

char buff[100];
int low, high, mid, cmp, top, ans;

int binarySearch(char str[]){
	low = 0, high = top -1;

	while(low <= high){

		mid = (low + high)/2;
		cmp = strcmp(str, dict[1][output[mid]]);
		if(cmp == 0)
			return mid;
		else if(cmp > 0)
			low = mid + 1;
		else if(cmp < 0)
			high = mid - 1;
	}

	return -1;
}

void quicksort( int start, int end, int array[] )
{
   if( start < end )
   {
       int piv = start;
       int i;
       int temp;
       for( i = start+1 ; i < end ; i++ )
           if( strcmp(dict[1][array[i]], dict[1][array[start]]) < 0 )
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
	freopen("q10282.in", "r", stdin);
	freopen("q10282.out", "w", stdout);
	#endif

	while(gets(buff) != NULL){
		if(buff[0] == '\0')		break;
		sscanf(buff, "%s%s", dict[0][top], dict[1][top]);
		output[top] = top++;
	}

	quicksort(0, top, output);

	while(gets(buff) != NULL){
		ans = binarySearch(buff);
		if(ans < 0)
			puts("eh");
		else
			puts(dict[0][output[ans]]);
	}
	return 0;
}
