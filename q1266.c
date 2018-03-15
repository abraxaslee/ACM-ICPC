// 0.004
#include <stdio.h>

int main(){

	int once = 0;
	int n, sqrtn, startpt, i, j;
	while(scanf("%d", &n)!=EOF){
		if(once==1){
			putchar(10);
		}
		int grid[15][15] ={};
		sqrtn = n*n;
		startpt = n/2;
		int x = startpt, y = 0;
		for(i=1;i<=sqrtn;i++){
			grid[y--][x++] = i;
			if(y<0){
				y = n-1;
			}
			if(x==n){
				x = 0;
			}
			if(grid[y][x]!=0){
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
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					printf("%2d", grid[i][j]);
				}
				putchar(10);
			}
		}else if(sqrtn<100){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					printf("%3d", grid[i][j]);
				}
				putchar(10);
			}
		}else if(sqrtn<1000){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					printf("%4d", grid[i][j]);
				}
				putchar(10);
			}
		}
		once = 1;
	}

	return 0;
}
