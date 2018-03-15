//2012/03/04
//11360.cpp
//Run time: 0.008

#include <stdio.h>

char cmd[100];
int matrix[10][10];
int size, i, j, transpose, caseNum;

void row(int a, int b){
	int temp;
	a -= 1, b -= 1;
	for(i=0; i<size; ++i){
		temp = matrix[a][i];
		matrix[a][i] = matrix[b][i];
		matrix[b][i] = temp;
	}
}

void col(int a, int b){
	int temp;
	a -= 1, b -= 1;
	for(i=0; i<size; ++i){
		temp = matrix[i][a];
		matrix[i][a] = matrix[i][b];
		matrix[i][b] = temp;
	}
}

void inc(){
	for(i=0; i<size; ++i)
		for(j=0; j<size; ++j){
			++matrix[i][j];
			if(matrix[i][j] == 10)
				matrix[i][j] = 0;
		}
}

void dec(){
	for(i=0; i<size; ++i)
		for(j=0; j<size; ++j){
			--matrix[i][j];
			if(matrix[i][j] == -1)
				matrix[i][j] = 9;
		}
}

void transprint(){
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j)
			printf("%1d", matrix[j][i]);
		putchar(10);
	}
}

void print(){
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j)
			printf("%1d", matrix[i][j]);
		putchar(10);
	}
}
void solve(){
	int x, y;
	switch(cmd[0]){

		case 't':
			transpose ^= 1;
			break;

		case 'r':
			sscanf(cmd, "%*s%d%d", &x, &y);
			if(transpose)
				col(x, y);
			else
				row(x, y);
			break;

		case 'c':
			sscanf(cmd, "%*s%d%d", &x, &y);
			if(transpose)
				row(x, y);
			else
				col(x, y);
			break;

		case 'i':
			inc();
			break;

		case 'd':
			dec();
			break;
	}
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11360.in", "r", stdin);
	freopen("11360.out", "w", stdout);
	#endif

	int testCase, query;
	scanf("%d", &testCase);
	while(testCase--){
		transpose = 0;
		scanf("%d", &size);
		for(i=0; i<size; ++i)
			for(j=0; j<size; ++j)
				scanf("%1d", &matrix[i][j]);

		scanf("%d", &query);	getchar();
		while(query--){
			gets(cmd);
			solve();
		}
		printf("Case #%d\n", ++caseNum);
		if(transpose)
			transprint();
		else
			print();

		putchar(10);
	}
	return 0;
}
