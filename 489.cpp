//2012/01/19
//489.cpp
//Run time: 0.104

#include <stdio.h>

char buff[100000];
int wordcount, LIFE, round, c, z;

void solve(int ans[]){
	int repeat[125] = {};
	LIFE = 7;
	for(z=0; buff[z] != '\0'; ++z){
		if(!repeat[buff[z]]){
				if(ans[buff[z]])
					wordcount--;
				else
					LIFE--;
			repeat[buff[z]] = 1;
		}
		if(!wordcount){
			puts("You win.");
			return;
		}
		if(!LIFE){
			puts("You lose.");
			return;
		}
	}
	puts("You chickened out.");
	return;
}

int main(){

	while(scanf("%d", &round)!=EOF){
		if(round == -1)	break;
		getchar();

		int ans[125] = {};

		while( (c = getchar()) != 10){
			ans[c] = 1;
		}

		wordcount = 0;
		for(c=97; c<123; ++c)
			if(ans[c])
				wordcount++;

		gets(buff);

		printf("Round %d\n", round);
		solve(ans);
	}
	return 0;
}
