//q10415.cpp - 2011/11/04
//accepted at 
//run time = 0.012
#include <stdio.h>

int notes[14][10] = {
	{0,1,1,1,0,0,1,1,1,1},
	{0,1,1,1,0,0,1,1,1,0},
	{0,1,1,1,0,0,1,1,0,0},
	{0,1,1,1,0,0,1,0,0,0},
	{0,1,1,1,0,0,0,0,0,0},
	{0,1,1,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{1,1,1,1,0,0,1,1,1,0},
	{1,1,1,1,0,0,1,1,0,0},
	{1,1,1,1,0,0,1,0,0,0},
	{1,1,1,1,0,0,0,0,0,0},
	{1,1,1,0,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0,0,0}
};

int hash[200];
char buffer[250];

void buildHash(void){
	hash['c'] = 0;
	hash['d'] = 1;
	hash['e'] = 2;
	hash['f'] = 3;
	hash['g'] = 4;
	hash['a'] = 5;
	hash['b'] = 6;

	hash['C'] = 7;
	hash['D'] = 8;
	hash['E'] = 9;
	hash['F'] = 10;
	hash['G'] = 11;
	hash['A'] = 12;
	hash['B'] = 13;
}

void solve(){
	int i, b, z; int button[10] = {}; int pressed[10] = {};
	for(i=0;buffer[i]!='\0';++i){
		b = hash[buffer[i]];
		for(z=0;z<10;++z){
			if(notes[b][z] && !pressed[z]){
				button[z]++;
				pressed[z] = 1;
			}
			if(!notes[b][z])
				pressed[z] = 0;
		}
	}
	printf("%d %d %d %d %d %d %d %d %d %d\n", button[0], button[1], button[2], button[3], 0, 0, button[6], button[7], button[8], button[9]);
	return;
}
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10415.in", "r", stdin);
	freopen("q10415.out", "w", stdout);
	#endif

	int caseNum;
	scanf("%d", &caseNum); getchar(); buildHash();
	while(caseNum--){
		gets(buffer);
		solve();
	}
	return 0;
}
