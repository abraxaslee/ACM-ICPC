//q11965.cpp - 2011/10/15
//accepted at 
//run time = 0.024 / 0.020
#include <stdio.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11965.in", "r", stdin);
	freopen("q11965.out", "w", stdout);
	#endif

	int caseNum, caseLine, currentCase = 0, c;
	scanf("%d", &caseNum);
	while(caseNum-- >0){
		scanf("%d", &caseLine);
		getchar();
		bool space = false;
		if(currentCase>0){
			putchar(10);
		}
		printf("Case %d:\n", ++currentCase);
		while(caseLine > 0){
			c = getchar();
			if(c == 32){
				if(space == false){
					space = true;
					putchar(c);
				}
			}else{
				space = false;
				if(c == -1){
					break;
				}
				if(c == 10){
					caseLine--;
				}
				putchar(c);
			}
		}
	}
	return 0;
}
