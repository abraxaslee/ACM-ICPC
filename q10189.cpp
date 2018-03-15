//q10189.cpp - 2011/09/07
//10189 - Minesweeper
//accepted at 2011-09-08 03:58:06
//run time = 0.012
#include <stdio.h>
using namespace std;

int main(){
	int fieldNum = 0;
	int n=0, m=0; // n=rows , m=cols
	char temp = 0;
	while(true){
	scanf(" %d %d", &n, &m);
		if(n+m==0){break;}
		fieldNum+=1;
		short bitMap[101][101] = {0};
		bool boom[100][100] = {false};
		//printf("DEBUG : n is %d and m is %d \n", n , m);

		//input
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf(" %c", &temp); // important space for discarding \n and any space
				if(temp==42){
					//printf("DEBUG : star is detected at [%d][%d].\n", i ,j);
					boom[i][j] = true;

					if(j>0){

						bitMap[i][j-1] +=1;
						bitMap[i+1][j-1] +=1;
					}
					if(i>0){
						bitMap[i-1][j] +=1;
						bitMap[i-1][j+1] +=1;
					}
					if(i>0&&j>0){
						bitMap[i-1][j-1] +=1;
					}
					bitMap[i][j+1] +=1;
					bitMap[i+1][j] +=1;
					bitMap[i+1][j+1] +=1;
				}
			}
		}
		if(fieldNum>1){printf("\n");}
		printf("Field #%d:\n", fieldNum);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(boom[i][j]){
					printf("*");
				}else{
					printf("%d", bitMap[i][j]);
				}
			}
			printf("\n");
		}

	}
	return 0;
}
