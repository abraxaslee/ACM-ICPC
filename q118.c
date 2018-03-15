// 0.004

#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q118.in", "r", stdin);
	freopen("q118.out", "w", stdout);
	#endif

	int mX, mY;
	scanf("%d %d", &mX, &mY);

	int dx[4] = { 0, 1, 0, -1};
	int dy[4] = { 1, 0, -1, 0};
	int dropPos[51][51] = {};
	char direction[4] = {'N','E','S','W'};
	char c;
	int X, Y, dir;
	while(scanf("%d %d %c\n", &X, &Y, &c)!=EOF){
		if(c == 'N'){
			dir = 0;
		}else if(c == 'E'){
			dir = 1;
		}else if(c == 'S'){
			dir = 2;
		}else{
			dir = 3;
		}
		int flagInbound = 1;
		while((c=getchar())!=10){
			if(flagInbound){
				if(c == 'R'){
					dir = (dir + 1)%4;
				}else if(c == 'L'){
					dir = (dir + 3)%4;
				}else if(c == 'F'){
					X += dx[dir];
					Y += dy[dir];
					if( X<0 || X>mX || Y>mY || Y<0 ){
						X -= dx[dir];
						Y -= dy[dir];
						if(dropPos[X][Y]==0){
							dropPos[X][Y] = 1;
							flagInbound = 0;
						}
					}
				}
			}
		}
		printf("%d %d %c", X, Y, direction[dir]);
		if(flagInbound == 1){
			putchar(10);
		}else{
			printf(" LOST\n");
		}
	}
	return 0;
}
