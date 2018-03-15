//2012/03/17
//10285.cpp
//Run time:

#include <stdio.h>

int height[105][105];
int row, col;

int BFS(){

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10285.in", "r", stdin);
	freopen("10285.out", "w", stdout);
	#endif

	int testCase, i, j, tmp, highest;
	char name[1000];
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%s%d%d", name, row, col);
		highest = -1;
		for(i=0; i<row; ++i)
			for(j=0; j<col; ++j){
				scanf("%d", &tmp);
				height[i][j] = tmp;
				if(tmp > highest)	highest = tmp;
			}

	}

	return 0;
}
