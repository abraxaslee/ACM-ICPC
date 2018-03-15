//q11734.cpp - 2011/12/10
//accepted at 
//run time = 0.004
#include <stdio.h>

char buff[2][25];

void solve(){

	int i, j, formatError;
	i = j = formatError = 0;
		while(buff[0][i] != '\0' || buff[1][j] !='\0'){
			if(buff[0][i] == buff[1][j]){
				i += 1;
				j += 1;
			}else{
				if(buff[0][i] == ' '){
					i += 1; formatError = 1;
				}else if(buff[1][j] == ' '){
					j += 1;  formatError = 1;
				}else{
					puts("Wrong Answer");
					return;
				}
			}
		}

	if( formatError )
		puts("Output Format Error");
	else
		puts("Yes");
	return;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11734.in", "r", stdin);
	freopen("q11734.out", "w", stdout);
	#endif

	int caseNum, current = 0;
	scanf("%d", &caseNum); getchar();
	while(caseNum--){
		gets(buff[0]);
		gets(buff[1]);
		printf("Case %d: ", ++current);
		solve();
	}
	return 0;
}
