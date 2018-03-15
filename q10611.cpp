//q10611.cpp - 2011/11/13
//accepted at 
//run time = 0.032
#include <stdio.h>

int ladies[50005];
int top;

int binarySearch(int search, int data[]){
	int low = 0, high = top -1;
	int mid;

	while(low <= high){

		mid = (low + high)/2;

		if(data[mid] == search)
			return mid;
		else if(search > data[mid])
			low = mid + 1;
		else if(data[mid] > search)
			high = mid - 1;

	}

	return -mid;
}

int traceDown(int search, int place){

	while(ladies[place] >= search && place >= 0)
		place--;

	if(place < 0)
		return -1;

	return place;
}

int traceUp(int search, int place){

	while(ladies[place] <= search && place < top)
		place++;

	if(place >= top)
		return -1;

	return place;
}

int main(){


	int Q, i, query, bSearch, up, down;

	scanf("%d", &top);
	for(i=0;i<top;++i)
		scanf("%d", &ladies[i]);

	scanf("%d", &Q);
	for(i=0;i<Q;++i){
		scanf("%d", &query);
		bSearch = binarySearch(query, ladies);

		if(bSearch < 0 ){
			up = traceUp(query, -bSearch);
			down = traceDown(query, -bSearch);

		}else{

			up = traceUp(query, bSearch);
			down = traceDown(query, bSearch);
		}

		if( down < 0)
			printf("X");
		else
			printf("%d", ladies[down]);

		if( up < 0)
			puts(" X");
		else
			printf(" %d\n", ladies[up]);
	}
	return 0;
}
