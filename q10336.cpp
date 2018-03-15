//q10336.cpp - 2011/10/22
//accepted at 
//run time = 0.008 c
#include <stdio.h>

int row, col;
char world[20][20] = {};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void DFS(int x, int y, char lang){
	world[x][y] = '.';
	int i;
	for(i=0;i<4;i++){
		int nx = x +dx[i];
		int ny = y +dy[i];
		if(nx >=0 && ny >= 0 && nx <row && ny < col && world[nx][ny] == lang)
			DFS(nx, ny, lang);
	}
}

//double quicksort, compare data refered by index, if equal, then sort the index it self to a certain order
void quicksort( int start, int end, int index[], int list[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; i++ ){
            if( list[index[i]] > list[index[start]] )
            {
                piv++;

                temp = index[i];
                index[i] = index[piv];
                index[piv] = temp;
            }else if(list[index[i]] == list[index[start]]){
            	if( index[i] < index[start] ){
            		piv++;

					temp = index[i];
					index[i] = index[piv];
					index[piv] = temp;
            	}
            }
        }
        temp = index[start];
        index[start] = index[piv];
        index[piv] = temp;

        quicksort( start, piv, index, list );
        quicksort( piv+1, end, index, list );
    }
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10336.in", "r", stdin);
	freopen("q10336.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0, i, j, maxNum;
	char c;
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d%d", &row, &col);
		getchar();
		int langList[26] = {};
		int output[26] = {}, top = 0;
		maxNum = 0;
		for(i=0;i<row;i++)
			gets(world[i]);

		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(world[i][j] != '.'){
					c = world[i][j];
					DFS(i,j,c);
					if(langList[c-97]++ == 0){
						output[top++] = c-97;
					}
				}
			}
		}
		quicksort(0, top, output, langList);
		printf("World #%d\n", ++currentCase);
		for(i=0;i<top;i++){
			printf("%c: %d\n", output[i]+97, langList[output[i]]);
		}
	}
	return 0;
}
