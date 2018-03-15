//q11713.cpp - 2011/12/10
//accepted at 
//run time = 0.004
#include <stdio.h>
#include <string.h>

char buff[2][25];
int length[2];
int vowels[300];

int solve(){
	length[0] = strlen(buff[0]); length[1] = strlen(buff[1]);
	if(length[0] != length[1])
		return 0;

	int i;
	for(i=0; i<length[0]; ++i)
		if(buff[0][i] != buff[1][i])
			if(!(vowels[buff[0][i]] && vowels[buff[1][i]])){
					return 0;
				}
	return 1;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11713.in", "r", stdin);
	freopen("q11713.out", "w", stdout);
	#endif

	int caseNum, i, failFlag;
	scanf("%d", &caseNum); getchar();
	vowels[97] = vowels[101] = vowels[105] = vowels[111] = vowels[117] = 1;
	while(caseNum--){
		gets(buff[0]); gets(buff[1]);
		if(solve())
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
