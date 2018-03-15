//2012/03/09
//11344.cpp
//Run time: 0.016
#include <stdio.h>
#include <string.h>
#define CARRY 1000000

char buff[1050];
int Big[500], S[12];
int top, set, length;

void parse_big(){
	static int add, i, j;
	length = strlen(buff);
	top = length /6;
	add = length %6;
	switch(add){
		case 1:
			sscanf(buff, "%1d", &Big[top++]);
			break;
		case 2:
			sscanf(buff, "%2d", &Big[top++]);
			break;
		case 3:
			sscanf(buff, "%3d", &Big[top++]);
			break;
		case 4:
			sscanf(buff, "%4d", &Big[top++]);
			break;
		case 5:
			sscanf(buff, "%5d", &Big[top++]);
			break;
		case 0:
			sscanf(buff, "%6d", &Big[top-1]);
			break;
	}

	if(add == 0) add = 6;

	for(i=add, j=top-2; i<length && j>=0; i+=6, --j)
		sscanf(buff + i, "%6d", &Big[j]);

}

int BigMod(int MOD){
	static int res, i, temp;
	res = 0;
	for(i=top-1; i>=0; --i){
		temp = Big[i] + res * CARRY;
		temp %= MOD;
		res = temp;
	}
	return (res == 0);
}

int solve(){
	static int i;
	for(i=0; i<set; ++i)
		if(BigMod(S[i]) == 0)
			return 0;
	return 1;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("11344.in", "r", stdin);
	freopen("11344.out", "w", stdout);
	#endif

	int testCase, i;
	scanf("%d", &testCase);
	while(testCase--){
		getchar();
		gets(buff);
		parse_big();
		scanf("%d", &set);
		for(i=0; i<set; ++i)
			scanf("%d", &S[i]);
		if(solve() == 0)
			printf("%s - Simple.\n", buff);
		else
			printf("%s - Wonderful.\n", buff);
	}
	return 0;
}
