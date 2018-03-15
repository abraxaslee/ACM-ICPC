//q1266.cpp - 2011/10/06
//accepted at 
//run time = 0.012
#include <stdio.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q1266.in", "r", stdin);
	freopen("q1266.out", "w", stdout);
	#endif
	bool once = false;
	int n, sqrtn, startpt;
	while(scanf("%d", &n)!=EOF){
		if(once==true){
			putchar(10);
		}
		int grid[15][15] ={};
		sqrtn = n*n;
		startpt = n/2;
		int x = startpt, y = 0;
		for(int i=1;i<=sqrtn;i++){
			//printf("[%d][%d] = %d\n", y, x, i);
			grid[y--][x++] = i;
			//jump to next , x+1 ,y-1
			//too high
			if(y<0){
				y = n-1;
			}
			//too right
			if(x==n){
				x = 0;
			}
			if(grid[y][x]!=0){
				//printf("[%d][%d] is blocked\n",y ,x);
				y += 2;
				x -= 1;
				if(y>=n){
					y=y-n;
				}
				if(x<0){
					x = n-1;
				}
			}
		}
		int sum[16] ={};
		sum[3] = 15;
		sum[5] = 65;
		sum[7] = 175;
		sum[9] = 369;
		sum[11] = 671;
		sum[13] = 1105;
		sum[15] = 1695;
		printf("n=%d, sum =%d\n", n, sum[n]);
		if(sqrtn<10){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%2d", grid[i][j]);
				}
				putchar(10);
			}
		}else if(sqrtn<100){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%3d", grid[i][j]);
				}
				putchar(10);
			}
		}else if(sqrtn<1000){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%4d", grid[i][j]);
				}
				putchar(10);
			}
		}
		once = true;
	}

	return 0;
}
