//q10954.cpp - 2011/10/20
//accepted at 2011/12/30
//run time = 0.024
#include <stdio.h>

int heap[5005];
int top;

void quicksort( int start, int end, int array[] ){
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

void push(int x){
	int i = top++;
	while( i > 0){
		int p = (i - 1)/2;
		if( heap[p] <= x )	break;
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
	return;
}

int pop(){
	int out = heap[0];
	int x = heap[--top];
	int i = 0;
	while( i *2 + 1 < top){
		int a = i * 2 + 1, b = i * 2 + 2;
		if( b < top && heap[b] < heap[a])	a = b;
		if(heap[a] >= x)		break;
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	return out;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10954.in", "r", stdin);
	freopen("q10954.out", "w", stdout);
	#endif

	int i;
	unsigned long int cost, total;

	while(scanf("%d", &top) == 1){
		if(top == 0)	break;
		total = cost = 0;
		for(i=0; i<top; ++i)
			scanf("%d", &heap[i]);

			quicksort(0, top, heap);
			while(top > 1){
				cost = pop() + pop();
				total += cost;
				push(cost);
			}
			printf("%lu\n", total);
		}
	return 0;
}
