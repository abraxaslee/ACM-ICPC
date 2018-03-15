//q12398.cpp - 2011/12/31
//accepted at 
//run time = 0.004
#include <stdio.h>

char buff[255];

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q12398.in", "r", stdin);
	freopen("q12398.out", "w", stdout);
	#endif

	int i, j, current=0;
	while(gets(buff)!=NULL){
		int grid[3][3] = {};
		for(i=0;buff[i]!='\0';++i)
			switch(buff[i]){
				case 'a':
					grid[0][0]++;
					grid[1][0]++;
					grid[0][1]++;
					break;
				case 'b':
					grid[0][1]++;
					grid[0][0]++;
					grid[0][2]++;
					grid[1][1]++;
					break;
				case 'c':
					grid[0][2]++;
					grid[0][1]++;
					grid[1][2]++;
					break;
				case 'd':
					grid[1][0]++;
					grid[0][0]++;
					grid[2][0]++;
					grid[1][1]++;
					break;
				case 'e':
					grid[1][1]++;
					grid[0][1]++;
					grid[1][0]++;
					grid[1][2]++;
					grid[2][1]++;
					break;
				case 'f':
					grid[1][2]++;
					grid[0][2]++;
					grid[1][1]++;
					grid[2][2]++;
					break;
				case 'g':
					grid[2][0]++;
					grid[1][0]++;
					grid[2][1]++;
					break;
				case 'h':
					grid[2][1]++;
					grid[1][1]++;
					grid[2][0]++;
					grid[2][2]++;
					break;
				case 'i':
					grid[2][2]++;
					grid[2][1]++;
					grid[1][2]++;
					break;
			}

			for(i=0;i<3; ++i)
				for(j=0; j<3; ++j)
					grid[i][j] %= 10;
			printf("Case #%d:\n",++current);
			printf("%d %d %d\n%d %d %d\n%d %d %d\n", grid[0][0], grid[0][1], grid[0][2], grid[1][0], grid[1][1], grid[1][2], grid[2][0], grid[2][1], grid[2][2]);

	}

	return 0;
}
