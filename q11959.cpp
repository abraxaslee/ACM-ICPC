//q11959.cpp - 2011/11/26
//accepted at 
//run time = 0.008 c
#include <stdio.h>

void turn_x(int dice[6]){
	int temp = dice[2];
	dice[2] = dice[3];
	dice[3] = dice[4];
	dice[4] = dice[5];
	dice[5] = temp;
	return;
}

void turn_y(int dice[6]){
	int temp = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[1];
	dice[1] = dice[4];
	dice[4] = temp;
	return;
}

void turn_z(int dice[6]){
	int temp = dice[0];
	dice[0] = dice[3];
	dice[3] = dice[1];
	dice[1] = dice[5];
	dice[5] = temp;
	return;
}

bool equal(int a[6], int b[6]){
	for(int i=0; i<6 ; ++i)
		if(a[i] != b[i])
			return false;
	return true;
}

bool sameDice(int a[6], int b[6]){
	int i, j;
	for(i = 0 ;i < 4 ; ++i){
		for(j = 0; j < 4; ++j){
			turn_x(b);
			if(equal(a,b))	return true;
		}
		for(j = 0; j < 4; ++j){
			turn_y(b);
			if(equal(a,b))	return true;
		}
			turn_z(b);
			if(equal(a,b))	return true;
	}
	return false;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11959.in", "r", stdin);
	freopen("q11959.out", "w", stdout);
	#endif

	int caseNum, a[6], b[6];
	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%1d%1d%1d%1d%1d%1d %1d%1d%1d%1d%1d%1d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &b[0], &b[1], &b[2], &b[3], &b[4], &b[5] );
		if(sameDice(a,b)==true)
			puts("Equal");
		else
			puts("Not Equal");
	}
	return 0;
}
