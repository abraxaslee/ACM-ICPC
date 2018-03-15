//q12015.cpp - 2011/11/26
//accepted at 
//run time = 0.020
#include <stdio.h>

char URL[10][105];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q12015.in", "r", stdin);
	freopen("q12015.out", "w", stdout);
	#endif

	int i, caseNum, currentCase = 0, score, highScore, outputTop;
	int output[10];
	scanf("%d", &caseNum);
	getchar();
	while(caseNum--){

		outputTop = 1;
		scanf("%s %d", URL[0], &highScore);
		output[0] = 0;

		for(i=1; i<10; ++i){
			scanf("%s %d", URL[i], &score);
			if(score > highScore){
				highScore = score;
				outputTop = 0;
				output[outputTop++] = i;
			}else if(score == highScore){
				output[outputTop++] = i;
			}
		}

		printf("Case #%d:\n", ++currentCase);
		for(i=0;i<outputTop; ++i)
			puts(URL[output[i]]);
	}
	return 0;
}
