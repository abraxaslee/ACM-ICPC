//2012/01/20
//11955.cpp
//Run time: 0.008

#include <stdio.h>
#include <string.h>

long long int coe[51][55];
int i, j, k, current;
char buff[100], *a, *b, *c;

void build_coe(){

	for(i=0; i<5; ++i){
		j = i*10;
		coe[j][0] = coe[j+1][0] = coe[j+2][0] = coe[j+3][0] = coe[j+4][0]
	= coe[j+5][0] = coe[j+6][0] = coe[j+7][0] = coe[j+8][0]
		       = coe[j+9][0] = 1;
	}
	for(i=0; i<51; ++i)
		for(coe[i][i]=j=1,k=i/2; j<=k; ++j)
			coe[i][j] = coe[i][i-j] = coe[i-1][j-1]+coe[i-1][j];

	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("11955.in", "r", stdin);
	freopen("11955.out", "w", stdout);
	#endif

	build_coe();
	int caseNum;

	scanf("%d", &caseNum); getchar();
	while(caseNum--){

		gets(buff);
		a = strtok(buff, "(+)^");
		b = strtok(NULL, "(+)^");
		sscanf(strtok(NULL, "(+)^"), "%d", &k);
		printf("Case %d: ", ++current);
		if(k == 1){
			printf("%s+%s\n", a, b);
			continue;
		}
		if(k == 2){
			printf("%s^2+2*%s*%s+%s^2\n", a, a, b, b);
			continue;
		}

		printf("%s^%d+%lld*%s^%d*%s", a, k, coe[k][1], a, k-1, b);
		for(i=2, j=k-1; i<j; ++i)
			printf("+%lld*%s^%d*%s^%d", coe[k][i], a, k-i, b, i);
		printf("+%lld*%s*%s^%d+%s^%d\n", coe[k][1], a, b, k-1, b, k);

	}

	return 0;
}
