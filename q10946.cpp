//q10946.cpp - 2011/11/21
//accepted at 
//run time = 0.020
#include <stdio.h>

char map[55][55];
char target;
int row, col, count, top;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1};

int hole[2505][2];
int output[2505];

void quicksort( int start, int end )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;

        for( i = start+1 ; i < end ; i++ ){
            if( hole[output[i]][0] > hole[output[start]][0])
            {
                piv++;

                temp = output[i];
                output[i] = output[piv];
                output[piv] = temp;

            }else if( hole[output[i]][0] == hole[output[start]][0] && hole[output[i]][1] < hole[output[start]][1] ){
            	piv++;

				temp = output[i];
				output[i] = output[piv];
				output[piv] = temp;
            }
        }

        temp = output[start];
        output[start] = output[piv];
        output[piv] = temp;

        quicksort( start, piv );
        quicksort( piv+1, end );
    }
}


void DFS(int x, int y){

	map[x][y] = '.';
	count += 1;

	for(int i=0;i<4;++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if( 0 <= nx && 0 <= ny && nx < row && ny < col)
			if(map[nx][ny] == target)
				DFS( nx, ny );
	}

	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q10946.in", "r", stdin);
	freopen("q10946.out", "w", stdout);
	#endif

	int i, j, problems = 0;
	while(scanf("%d %d", &row, &col)!=EOF && row + col > 0){
		getchar();
		for(i=0;i<row;++i)
			gets(map[i]);

		top = 0;
		for(i=0;i<row;++i)
			for(j=0;j<col;++j)
				if( map[i][j] != '.'){
					target = map[i][j];
					count = 0;
					DFS(i,j);
					hole[top][0] = count;
					hole[top][1] = (int)target;
					output[top] = top;
					top += 1;
				}

		quicksort( 0, top);
		printf("Problem %d:\n", ++problems);
		for(i=0;i<top;i++)
		printf("%c %d\n", hole[output[i]][1], hole[output[i]][0]);
	}
	return 0;
}
