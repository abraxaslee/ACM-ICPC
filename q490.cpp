//q490.cpp - 2011/12/18
//accepted at 
//run time = 0.020
#include <stdio.h>
#include <string.h>

char buff[101][105];
int length[100];


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q490.in", "r", stdin);
	freopen("q490.out", "w", stdout);
	#endif

	int row, col, i, j;
	row = col = 0;
	while(gets(buff[row])!=NULL){
		length[row] = strlen(buff[row]);
		if(length[row] > col)
			col = length[row];
		++row;
	}

	for(j=0; j<col; ++j){
		for(i=row-1; i >=0; --i)
			if(j < length[i])
				putchar(buff[i][j]);
			else
				putchar(32);

		putchar(10);
	}

	return 0;
}
