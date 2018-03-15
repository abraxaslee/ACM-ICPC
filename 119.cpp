//2012/02/17
//119.cpp
//Run time: 0.004

#include <stdio.h>
#include <string.h>

char names[1000], buff[1000], *token;
char *friends[10];
int pocket[10];
int once;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("119.in", "r", stdin);
	//freopen("119.out", "w", stdout);
	#endif

	int people, i , j, z, share, gift, taker, temp;
	while( scanf("%d", &people) != EOF ){
		getchar();
		gets(names);
		for(i=0, token = strtok(names, " "); i<people; token = strtok(NULL, " "), ++i)
			friends[i] = token, pocket[i] = 0;

		for(z=0; z<people; ++z){
			gets(buff);
			token = strtok(buff, " ");
			for(i=0; i<people; ++i)
				if(strcmp(token, friends[i]) == 0)
					break;

			token = strtok(NULL, " ");
			sscanf(token, "%d", &temp);

			token = strtok(NULL, " ");
			sscanf(token, "%d", &share);
			if(share == 0)
				continue;

			gift = temp / share;
			pocket[i] -= gift * share;
			for(token=strtok(NULL, " "), i=0; i<share; token=strtok(NULL, " "), ++i)
				for(j=0; j<people; ++j)
					if(strcmp(friends[j], token) == 0)
						{pocket[j] += gift; break;}
		}
		if(once) putchar(10);
		for(i=0; i<people; ++i)
			printf("%s %d\n", friends[i], pocket[i]);

		once = 1;
	}

	return 0;
}
