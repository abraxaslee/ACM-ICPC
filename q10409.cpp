//q10409.cpp - 2011/12/25
//accepted at 
//run time = 0.008
#include <stdio.h>
// 0 = top, 1 = north, 2 = west

char buff[15];
int dice[3];
int tmp;

void north(){
	tmp = dice[0];
	dice[0] = 7 - dice[1];
	dice[1] = tmp;
}

void west(){
	tmp = dice[0];
	dice[0] = 7 - dice[2];
	dice[2] = tmp;
}

void south(){
	tmp = dice[0];
	dice[0] = dice[1];
	dice[1] = 7 - tmp;
}

void east(){
	tmp = dice[0];
	dice[0] = dice[2];
	dice[2] = 7 - tmp;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q10409.in", "r", stdin);
	freopen("q10409.out", "w", stdout);
	#endif

	int command;
	while(scanf("%d", &command)==1){
		getchar();
		if(command == 0)	break;
		dice[0] = 1, dice[1] = 2, dice[2] = 3;
		while(command--){
			gets(buff);
			if(buff[0] == 'n')
				north();
			else if(buff[0] == 's')
				south();
			else if(buff[0] == 'w')
				west();
			else if(buff[0] == 'e')
				east();
		}
		putchar(48+dice[0]);	putchar(10);
	}
	return 0;
}
