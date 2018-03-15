//q253.cpp - 2011/11/27
//accepted at 
//run time = 0.008
#include <stdio.h>

void turn_x(char dice[]){
	char temp = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[4];
	dice[4] = dice[3];
	dice[3] = temp;
	return;
}

void turn_y(char dice[]){
	char temp = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[3];
	dice[3] = temp;
	return;
}

void turn_z(char dice[]){
	char temp = dice[0];
	dice[0] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[4];
	dice[4] = temp;
	return;
}

bool equal(char a[], char b[]){
	for(int i=0; i<6 ; ++i)
		if(a[i] != b[i])
			return false;
	return true;
}

bool sameDice(char a[], char b[]){
	int i, j;
	if(equal(a,b))	return true;

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
	freopen("q253.in", "r", stdin);
	freopen("q253.out", "w", stdout);
	#endif

	int caseNum;
	char a[7], b[7];
	while(scanf("%6s%6s", a, b )!=EOF){
		if(sameDice(a,b)==true)
			puts("TRUE");
		else
			puts("FALSE");
	}
	return 0;
}
