//q409.cpp - 2012/01/05
//accepted at 
//run time = 0.004
#include <stdio.h>
#include <string.h>

char keyword[20][25];
char excuse[20][101];
char buffer[101];
int output[20];
int top, K, E;


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q409.in", "r", stdin);
	freopen("q409.out", "w", stdout);
	#endif

	int i, j, words, worse, current = 0;
	char *token;
	while(scanf("%d%d", &K, &E) == 2){
		getchar();
		top = worse = 0;

		for(i=0; i<K; ++i)
			gets(keyword[i]);
		for(i=0; i<E; ++i)
			gets(excuse[i]);

		for(i=0; i<E; ++i){
			strcpy(buffer, excuse[i]);
			token = strtok(buffer," @#\".,!?&");
			words = 0;
			while(token != NULL){
				for(j=0; j<K; ++j)
					if(strcasecmp(keyword[j], token)==0){
						words++;	break;
					}
				token = strtok(NULL," @#\".,!?&");
			}

			if(words > worse){
				top = 0;
				worse = words;
				output[top++] = i;
			}else if(words == worse){
				output[top++] = i;
			}
		}

		printf("Excuse Set #%d\n", ++current);
		for(i=0; i<top; ++i)
			puts(excuse[output[i]]);
		putchar(10);
	}
	return 0;
}
