//q320.cpp - 2011/12/29
//accepted at 
//run time = 0.004

#include <stdio.h>
#include <string.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q320.in", "r", stdin);
	freopen("q320.out", "w", stdout);
	#endif

	int mapNum = 0, caseNum, c, x, y;
	char bitmap[32][33];

	scanf("%d", &caseNum);

	while(caseNum--){

		memset(bitmap, '.', sizeof(bitmap));

		scanf("%d%d", &x, &y);	getchar();
		while((c = getchar()) && c != '.')
			switch(c){
				case 'W':
					bitmap[y][--x] = 'X';
					break;
				case 'E':
					bitmap[y-1][x++] = 'X';
					break;
				case 'N':
					bitmap[y++][x] = 'X';
					break;
				case 'S':
					bitmap[--y][x-1] = 'X';
					break;
			}


			printf("Bitmap #%d\n", ++mapNum);
			for(c=31; c>=0; --c){
				bitmap[c][32] = '\0';
				puts(bitmap[c]);
			}
			putchar(10);

	}
	return 0;
}
