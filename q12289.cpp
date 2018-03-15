//q12289.cpp - 2011/10/01
//accepted at 2011-10-01 05:16:39
//run time = 0.008
#include <stdio.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q12289.in", "r", stdin);
	freopen("q12289.out", "w", stdout);
	#endif

	int caseNum;
	scanf("%d", &caseNum);
	while(caseNum-- >0){
		char c[6] = {};
		bool one[3] = {false};
		scanf("%s", c);
		if(c[4]=='\0'){
			if(c[0]=='o'){
				one[0] = true;
			}
			if(c[1]=='n'){
				one[1] = true;
			}
			if(c[2]=='e'){
				one[2] = true;
			}

			if( (one[0]+one[1]+one[2])>=2){
						putchar(49);
					}else{
						putchar(50);
					}

		}else{
			putchar(51);
		}
		putchar(10);
	}
	return 0;
}
