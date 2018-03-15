//q12325.cpp - 2011/10/24
//accepted at 
//run time = 
	#include <stdio.h>

	int main(){

		#ifndef ONLINE_JUDGE
		freopen("q12325.in", "r", stdin);
		freopen("q12325.out", "w", stdout);
		#endif

		double totalA, totalB;
		int caseNum, currentCase = 0, chest, tmpchest, S1, V1, S2, V2, tmp;
		scanf("%d", &caseNum);
		while(caseNum--){
			scanf("%d%d%d%d%d", &chest, &S1, &V1, &S2, &V2);

				tmpchest = chest;
				tmp = tmpchest/S1;
				totalA = tmp * (double)V1;
				tmpchest -= tmp * S1;
				totalA += tmpchest/S2 * (double)V2;

				tmpchest = chest;
				tmp = tmpchest/S2;
				totalB = tmp * (double)V2;
				tmpchest -= tmp * S2;
				totalB += tmpchest/S1 * (double)V1;
	
				++currentCase;
			if(totalA >= totalB){
				printf("Case #%d: %.0lf\n", currentCase, totalA);
			}else{
				printf("Case #%d: %.0lf\n", currentCase, totalB);
			}
		}
		return 0;
	}
