//2012/01/17
//12403.cpp
//Run time: 0.008

#include <stdio.h>
char buff[20];
char* amount = &buff[6];
int fund;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("12403.in", "r", stdin);
	freopen("12403.out", "w", stdout);
	#endif

	int operation, tmp;
	scanf("%d", &operation);	getchar();
	while(operation--){
		gets(buff);
		if(buff[0] == 'd'){
			sscanf(amount, "%d", &tmp);
			fund += tmp;
		}else
		  printf("%d\n", fund);

	}
	return 0;
}
