//q11498.cpp - 2011/11/14
//accepted at 
//run time = 0.004
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11498.in", "r", stdin);
	freopen("q11498.out", "w", stdout);
	#endif

	int queryNum, starX, starY, qX, qY;
	while(scanf("%d", &queryNum)==1 && queryNum > 0){
		scanf("%d %d", &starX, &starY);
		while(queryNum--){
			scanf("%d %d", &qX, &qY);
			if( starX == qX || starY == qY){
				puts("divisa");
				continue;
			}

			if( qX > starX ){
				if( qY > starY )
					puts("NE");
				else
					puts("SE");
			}else{
				if( qY > starY)
					puts("NO");
				else
					puts("SO");
			}
		}
	}
	return 0;
}
