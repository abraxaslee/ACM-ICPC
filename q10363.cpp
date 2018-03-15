//q10363.cpp - 2011/12/18
//accepted at 
//run time = 0.008
#include <stdio.h>

char grid[3][5];
int countX, countO;

int isOwin(){
	int i;
	for(i=0; i<3; ++i){
		if(grid[0][i] == 'O' && grid[1][i] == 'O' && grid[2][i] == 'O')
			return 1;
		if(grid[i][0] == 'O' && grid[i][1] == 'O' && grid[i][2] == 'O')
			return 1;
	}
	if(grid[1][1] == 'O'){
		if(grid[0][0] == 'O' && grid[2][2] == 'O')
			return 1;
		if(grid[2][0] == 'O' && grid[0][2] == 'O')
			return 1;
	}
	return 0;
}
int isXwin(){
	int i;
	for(i=0; i<3; ++i){
		if(grid[0][i] == 'X' && grid[1][i] == 'X' && grid[2][i] == 'X')
			return 1;
		if(grid[i][0] == 'X' && grid[i][1] == 'X' && grid[i][2] == 'X')
			return 1;
	}
	if(grid[1][1] == 'X'){
		if(grid[0][0] == 'X' && grid[2][2] == 'X')
			return 1;
		if(grid[2][0] == 'X' && grid[0][2] == 'X')
			return 1;
	}
	return 0;
}
void count(){
	int i, j;
	countO = countX = 0;
	for(i=0; i<3; ++i)
		for(j=0; j<3; ++j){
			if(grid[i][j] == 'O')
				++countO;
			else if(grid[i][j] == 'X')
				++countX;
		}
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10363.in", "r", stdin);
	freopen("q10363.out", "w", stdout);
	#endif

	int caseNum, winX, winO, bothWin, statO, statX, tmp;
	scanf("%d", &caseNum);

	while(caseNum--){
		getchar();
		gets(grid[0]);		gets(grid[1]);		gets(grid[2]);

		winX = isXwin();
		winO = isOwin();
		bothWin = winX + winO;
		if(bothWin == 2){
			puts("no");
			continue;
		}
		count();
		statO = (countX == countO);
		statX = (countX == countO+1);

		if( winX  & statX)
			puts("yes");
		else if(winO & statO)
			puts("yes");
		else if( !bothWin & (statX | statO) )
			puts("yes");
		else
			puts("no");

	}
	return 0;
}
