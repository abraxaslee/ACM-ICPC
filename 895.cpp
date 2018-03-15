//2012/03/05
//895.cpp
//Run time: 0.008

#include <stdio.h>

int dictionary[1005][200];
int puzzle[200];
int top;


int match(int x){
	int i;
	for(i=97; i<123; ++i)
		if(puzzle[i] < dictionary[x][i])
			return 0;
	return 1;
}

void clear(){
	int i;
	for(i=97; i<123; ++i)
		puzzle[i] = 0;
}


void solve(){
	int z, ans;
	for(ans=z=0; z<top; ++z)
		ans += match(z);
	printf("%d\n", ans);
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("895.in", "r", stdin);
	freopen("895.out", "w", stdout);
	#endif

	int c;
	while( (c = getchar()) != '#' ){
		if( c == 10)	{++top;	continue;}
		++dictionary[top][c];
	}

	getchar();

	while( (c = getchar()) != '#' ){
		if( c == 10)	{solve(); clear();	continue;}
		++puzzle[c];
	}
	return 0;
}
