//2012/01/16
//11362.cpp
//Run time: 0.080

#include <stdio.h>
#include <string.h>
char phone[10000][11];
int list[10000];
int top;

void quicksort( int start, int end, int array[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; i++ ){
            if( strcmp(phone[array[i]], phone[array[start]]) < 0)
            {
                piv++;

                temp = array[i];
                array[i] = array[piv];
                array[piv] = temp;
            }
        }

        temp = array[start];
        array[start] = array[piv];
        array[piv] = temp;

        quicksort( start, piv, array );
        quicksort( piv+1, end, array );
    }
}

int isCosist(int A, int B){
	int i;
	for(i=0; phone[A][i] != '\0' & phone[B][i] != '\0'; ++i)
		if(phone[A][i] != phone[B][i])
			return 0;
	return 1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11362.in", "r", stdin);
	freopen("11362.out", "w", stdout);
	#endif

	int CaseNum, i;
	scanf("%d", &CaseNum);
	while(CaseNum--){
		scanf("%d", &top);	getchar();
		for(i = 0; i < top; ++i){
			gets(phone[i]);
			list[i] = i;
		}
		quicksort(0, top, list);
		for(i = 1; i < top; ++i){
			if(isCosist(list[i-1], list[i]))
				break;
		}

		if(i == top)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
