//2012/02/17
//12405.cpp
//Run time: 0.004

#include <stdio.h>
char field[105];
int testCase, caseNum, top, result, i;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("12405.in", "r", stdin);
	freopen("12405.out", "w", stdout);
	#endif

	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d", &top); getchar();
		gets(field);

		for(result=i=0; i<top; ++i)
			if(field[i] == '.')
				i+=2, ++result;
		printf("Case %d: %d\n", ++caseNum, result);
	}
	return 0;
}
