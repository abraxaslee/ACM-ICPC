//2012/01/19
//496.cpp
//Run time: 0.008

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buff[10005];
struct SET{ int num[1000]; int size, front, next, extra;} setA, setB;

void quicksort( int start, int end, int array[] )
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

int main(){

	#ifndef ONLINE_JUDGE
	freopen("496.in", "r", stdin);
	freopen("496.out", "w", stdout);
	#endif

	int inter, i, j;
	char *token;

	while(gets(buff) != NULL){

		for(token = strtok(buff, " "), i = 0; token; ++i, token = strtok(NULL, " "))
			setA.num[i] = atoi(token);
		setA.size = i;

		gets(buff);
		for(token = strtok(buff, " "), i = 0; token; ++i, token = strtok(NULL, " "))
			setB.num[i] = atoi(token);
		setB.size = i;

		quicksort(0, setA.size, setA.num);
		quicksort(0, setB.size, setB.num);

		setA.extra = setB.extra = setA.next = setB.next = setA.front = setB.front = inter = 0;
		while( setA.front < setA.size & setB.front < setB.size ){
			while(setA.next < setA.size & setA.num[setA.next] == setA.num[setA.front]){
				++setA.next;
			}
			setA.extra += setA.next - setA.front - 1;
			setA.front = setA.next - 1;

			while(setB.next < setB.size & setB.num[setB.next] == setB.num[setB.front]){
				++setB.next;
			}
			setB.extra += setB.next - setB.front - 1;
			setB.front = setB.next - 1;

			if(setA.num[setA.front] < setB.num[setB.front])
				++setA.front;
			else if(setA.num[setA.front] > setB.num[setB.front])
				++setB.front;
			else{
				++setA.front; ++setB.front; ++inter;
			}
		}


		setA.size -= setA.extra;
		setB.size -= setB.extra;
		setA.front -= setA.extra;
		setB.front -= setB.extra;


		if(inter == setA.size & inter == setB.size)
			puts("A equals B");
		else if(inter == setA.size)
			puts("A is a proper subset of B");
		else if(inter == setB.size)
			puts("B is a proper subset of A");
		else if(!inter)
			puts("A and B are disjoint");
		else
			puts("I'm confused!");

	}
	return 0;
}
