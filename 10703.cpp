//2012/02/27
//10703.cpp
//Run time: 0.028
#include <stdio.h>
#include <string.h>

typedef struct coordinate{ int x, y; } point;
int spot[500][500];
int W, H, N;

void swap(int *x, int *y){
	int z = *x;
	*x = *y, *y = z;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("10703.in", "r", stdin);
	freopen("10703.out", "w", stdout);
	#endif

	int i, j, ans;
	while(scanf("%d%d%d", &W, &H, &N) == 3){
		if( W + H + N == 0 )	break;
		point a, b;

		while(N--){
			scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
			if(a.x > b.x)
				swap(&a.x, &b.x);
			if(a.y > b.y)
				swap(&a.y, &b.y);

			for(i = a.y -1; i < b.y; ++i)
				for(j = a.x -1; j < b.x; ++j)
					spot[i][j] = 1;
		}

		for(ans = i = 0; i < H; ++i)
			for(j = 0; j < W; ++j)
				if(spot[i][j] == 0)
					++ans;

		if(ans == 0)
			puts("There is no empty spots.");
		else if(ans == 1)
			puts("There is one empty spot.");
		else
			printf("There are %d empty spots.\n", ans);

		memset(spot, 0, sizeof(spot));
	}
	return 0;
}
