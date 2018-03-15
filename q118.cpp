//q118.cpp - 2011/10/07
//accepted at
//run time = 0.008
#include <stdio.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q118.in", "r", stdin);
	freopen("q118.out", "w", stdout);
	#endif



	int mX, mY; //max X and max Y
	scanf("%d %d", &mX, &mY);

	int dx[4] = { 0, 1, 0, -1}; //N , E , S , W
	int dy[4] = { 1, 0, -1, 0};
	bool dropPos[51][51] = {};
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
		bool flagInbound = true;
		while((c=getchar())!=10){
			if(flagInbound){
				if(c == 'R'){
					dir = (dir + 1)%4;
				}else if(c == 'L'){
					dir = (dir + 3)%4;
				}else if(c == 'F'){
					X += dx[dir];
					Y += dy[dir];
					//printf("%d %d\n", X ,Y);
					if( X<0 || X>mX || Y>mY || Y<0 ){
						X -= dx[dir];
						Y -= dy[dir];
						//printf("-[%d %d]\n", X ,Y);
						if(dropPos[X][Y]==false){
							dropPos[X][Y] = true;
							//printf("dropPos[%d][%d] = true\n", X, Y);
							flagInbound = false;
						}
					}
				}
			}
		}
		printf("%d %d %c", X, Y, direction[dir]);
		if(flagInbound == true){
			putchar(10);
		}else{
			printf(" LOST\n");
		}
	}
	return 0;
}
