//2012/04/01
//10377.cpp
//Run time: 0.004

#include <stdio.h>

char maze[65][65];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10377.in", "r", stdin);
	freopen("10377.out", "w", stdout);
	#endif

	int testCase, i, c, once;
	int row, col, rx, ry, dir, nx, ny;
	const int dx[4] = { -1, 0, 1, 0 };
	const int dy[4] = { 0, 1, 0, -1 };

	once = 0;

	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d%d", &row, &col);	getchar();
		for(i=0; i<row; ++i)
			gets(maze[i]);
		scanf("%d%d", &rx, &ry);

		dir = 0;

		while((c = getchar()) != 'Q'){
			if(c == 'R'){
				if(dir == 3)
					dir = 0;
				else
					dir += 1;
			}else if(c == 'L'){
				if(dir == 0)
					dir = 3;
				else
					dir -= 1;
			}else if(c == 'F'){
				nx = rx + dx[dir], ny = ry + dy[dir];
				if(0 <= nx && nx < row && 0 <= ny && ny < col && maze[nx][ny] != '*')
					rx = nx, ry = ny;
			}
		}

		if(once) putchar(10);

		printf("%d %d ", rx +1, ry +1);
		switch(dir){
			case 0: putchar('N'); break;
			case 1: putchar('E'); break;
			case 2: putchar('S'); break;
			case 3: putchar('W'); break;
		}
		putchar(10);

		once = 1;
	}
	return 0;
}
