//q624.cpp - 2011/10/20
//accepted at 
//run time = 0.032 c
#include <stdio.h>
using namespace std;

int length, n, bestLength, bestCD;
int tracks[20], best[20];


void backTrack(int i, int CD, int myTrack[20], int myLength){
	if(i==n){
		if(bestLength <= myLength){
			for(int z=0;z<CD;++z){
				best[z] = myTrack[z];
			}
			bestLength = myLength;
			bestCD = CD;
		}
		return;
	}

	backTrack(i+1, CD, myTrack, myLength);
	if(myLength + tracks[i] <= length){
		myTrack[CD++] = tracks[i];
		myLength += tracks[i];
		backTrack(i+1, CD, myTrack, myLength);
	}
	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q624.in", "r", stdin);
	freopen("q624.out", "w", stdout);
	#endif


	while(scanf("%d%d", &length, &n) == 2){
		//input tracks
		for(int i=0;i<n;i++){
			scanf("%d", &tracks[i]);
		}
		int mytrack[20] = {};
		bestLength = 0; bestCD = 0;
		backTrack( 0, 0, mytrack, 0 );
		for(int i=0;i<bestCD;++i)
			printf("%d ", best[i]);
		printf("sum:%d\n", bestLength);
	}
	return 0;
}
