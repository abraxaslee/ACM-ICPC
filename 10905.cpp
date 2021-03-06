//2012/03/11
//10905.cpp
//Run time: 0.064
#include <stdio.h>
#include <string.h>

char childnum[55][40];
int output[55];

int GCD(int x, int y){

	static int temp;

	while(x % y != 0){
		temp = y;
		y = x % y;
		x = temp;
	}

	return y;
}

int LCM(int x, int y){
	return  x * y / GCD(x , y);
}

int childcmp(char *c1, char *c2){
	static int c1len, c2len, limit, i, a, b;
	c1len = strlen(c1), c2len = strlen(c2);

	if(c1len == c2len)
		limit = c1len;
	else
		limit = LCM(c1len, c2len);

	for(a=b=i=0; i<limit; ++i){

		if( *(c1 + a) < *(c2 + b) )
			return 0;

		if( *(c1 + a) > *(c2 + b) )
			return 1;

		++a, ++b;
		if(a == c1len)	a = 0;
		if(b == c2len)	b = 0;
	}
	return 0;
}

void quicksort( int start, int end )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; ++i )
            if( childcmp(childnum[output[i]], childnum[output[start]]) )
            {
                ++piv;

                temp = output[i];
                output[i] = output[piv];
                output[piv] = temp;
            }

        temp = output[start];
        output[start] = output[piv];
        output[piv] = temp;

        quicksort( start, piv );
        quicksort( piv+1, end );
    }
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("10905.in", "r", stdin);
	freopen("10905.out", "w", stdout);
	#endif

	int N, i;
	while(scanf("%d", &N) == 1){
		if(N == 0)	break;

		for(i=0; i<N; ++i)
			scanf("%s", childnum[i]), output[i] = i;

		quicksort(0, N);

		for(i=0; i<N; ++i)
			printf("%s", childnum[output[i]]);

		putchar(10);
	}

	return 0;
}
