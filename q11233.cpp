//q11233.cpp - 2011/12/11
//accepted at 
//run time = 0.004
#include <stdio.h>
#include <string.h>

int vowels[300];
char table[20][2][50];
int top;
char buff[50];
int last;

int check_table(){
	int i;
	for(i = 0 ; i < top ; ++i){
		//printf("compare_%s_with_%s\n", table[i][0], buff);
		if(strcmp(table[i][0], buff) == 0)
			return i;
	}
	return -1;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11233.in", "r", stdin);
	freopen("q11233.out", "w", stdout);
	#endif

	int query, i, tmp;
	vowels[97] = vowels[101] = vowels[105] = vowels[111] = vowels[117] = 1;
	scanf("%d%d", &top, &query);

	for(i = 0 ; i < top ; ++i)
		scanf("%s %s", &table[i][0], &table[i][1]);
	getchar();

	while(query--){
		gets(buff);
		tmp = check_table();
		if(tmp >= 0){
			puts(table[tmp][1]);
			continue;
		}

		last = strlen(buff) -1;
		if(buff[last] == 'y' && vowels[buff[last-1]] == 0){
			buff[last] = 'i';
			buff[last+1] = 'e';
			buff[last+2] = 's';
			buff[last+3] = '\0';
			puts(buff);
			continue;
		}

		if(buff[last] == 'o' || buff[last] == 's' || buff[last] == 'x' || (buff[last] == 'h' && (buff[last-1] == 'c' || buff[last-1] == 's'))){
			buff[last+1] = 'e';
			buff[last+2] = 's';
			buff[last+3] = '\0';
			puts(buff);
			continue;
		}
		buff[last+1] = 's';
		buff[last+2] = '\0';
		puts(buff);
	}
	return 0;
}
