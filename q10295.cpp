//q10295.cpp - 2011/11/11
//accepted at 
//run time = 0.004c
#include <stdio.h>
#include <string.h>

char hayChar[1000][20];
int hayPoint[1000];
int hayMax;

int find(char* str){
	int i,j;
	for(i=0;i<hayMax;++i){
		if(strcmp(hayChar[i], str) == 0)
			return hayPoint[i];
	}
	return 0;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10295.in", "r", stdin);
	freopen("q10295.out", "w", stdout);
	#endif

	int desc, i;
	scanf("%d%d", &hayMax, &desc);
	for(i=0;i<hayMax;++i)
		scanf("%s %d", hayChar[i], &hayPoint[i]);

	int result = 0; char str[1000];
	while(desc){
		scanf("%s", str);
		if(str[0] == '.' && str[1] == '\0'){
			--desc;
			printf("%d\n", result);
			result = 0;
		}else{
			result += find(str);
		}
	}
	return 0;
}
