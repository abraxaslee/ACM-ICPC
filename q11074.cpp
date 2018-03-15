//q11074.cpp - 2011/12/11
//accepted at 
//run time = 0.012
#include <stdio.h>
#include <string.h>
#define MAX 1000
char horizon[MAX];
char table[MAX];
char vertic[25];
char square[25];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11074.in", "r", stdin);
	freopen("q11074.out", "w", stdout);
	#endif

	int S, T, N, i, j, length, current = 0;

	for(i=0; i<MAX; ++i)
		horizon[i] = '*';
	for(i=0; i<25; ++i){
		vertic[i] = '*';		square[i] = '.';
	}

	while(scanf("%d%d%d", &S, &T, &N)!=EOF){
		if(S+T+N == 0)		break;

		length = N * ( S + T ) + T;
		horizon[length] = '\0';
		vertic[T] = '\0';
		square[S] = '\0';
		table[0] = '\0';
		for(i=0; i<N; ++i){
			strcat(table, vertic);
			strcat(table, square);
		}
		strcat(table, vertic);


		printf("Case %d:\n", ++current);
		for(j=0; j<N; ++j){
			for(i=0; i<T; ++i)
				puts(horizon);
			for(i=0; i<S; ++i)
				puts(table);
		}
		for(i=0; i<T; ++i)
			puts(horizon);

		putchar(10);

		horizon[length] = '*';
		vertic[T] = '*';
		square[S] = '.';
		table[0] = '\0';
	}
	return 0;
}
