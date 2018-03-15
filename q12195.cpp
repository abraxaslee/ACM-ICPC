//q12195.cpp - 2011/10/16
//accepted at 
//run time = 0.020(c)
#include <stdio.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q12195.in", "r", stdin);
	freopen("q12195.out", "w", stdout);
	#endif

	int c, duration, correct = 0;
	while( ((c=getchar())!= EOF)&& c != '*'){

		if(c == '/'){
			if(duration == 64){
				correct += 1;
			}
			duration = 0;
			continue;
		}

		if(c == 10){
			printf("%d\n", correct);
			correct = 0;
			continue;
		}

			switch(c){

				case 87:
					duration += 64;
					break;

				case 72:
					duration += 32;
					break;

				case 81:
					duration += 16;
					break;

				case 69:
					duration += 8;
					break;

				case 83:
					duration += 4;
					break;

				case 84:
					duration += 2;
					break;

				case 88:
					duration += 1;
					break;

			}
	}
	return 0;
}
