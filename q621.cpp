//q621.cpp - 2011/12/04
//accepted at 
//run time = 0.004
#include <stdio.h>
#include <string.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q621.in", "r", stdin);
	freopen("q621.out", "w", stdout);
	#endif

	int caseNum, last; char buff[1000];
	scanf("%d", &caseNum); getchar();
	while(caseNum--){
		gets(buff);
		if(buff[1] == '\0'){
			if(buff[0] == '1' || buff[0] == '4'){
				putchar('+'); putchar(10); continue;
			}
		}

		if(buff[0] == '7' && buff[1] == '8' && buff[2] == '\0'){
			putchar('+'); putchar(10); continue;
		}

		last = strlen(buff)-1;
		if(buff[last] == '5' && buff[last-1] == '3'){
			putchar('-'); putchar(10); continue;
		}

		if(buff[0] == '9' && buff[last] == '4'){
			putchar('*'); putchar(10); continue;
		}

		if(buff[0] == '1' && buff[1] == '9' && buff[2] == '0'){
			putchar('?'); putchar(10); continue;
		}
	}

	return 0;
}
