//q11777.cpp - 2011/12/10
//accepted at 
//run time = 0.004
#include <stdio.h>

int min(int numA, int numB){
	return numA < numB ? numA : numB;
}

int main(){

	int test[3];
	int caseNum, i, marks, grade, tmp, current = 0;
	scanf("%d", &caseNum);
	while(caseNum--){
		grade = 0;
		for(i = 0; i < 4 ; ++i){
			scanf("%d", &marks);
			grade += marks;
		}
		scanf("%d%d%d", &test[0], &test[1], &test[2]);
		tmp = test[0] + test[1] + test[2] - min(test[0], min(test[1], test[2]));
		grade += tmp/2;
		grade /= 10;

		switch(grade){
			case 10:
			case 9:
				printf("Case %d: A\n", ++current);
				break;
			case 8:
				printf("Case %d: B\n", ++current);
				break;
			case 7:
				printf("Case %d: C\n", ++current);
				break;
			case 6:
				printf("Case %d: D\n", ++current);
				break;
			default:
				printf("Case %d: F\n", ++current);
				break;
		}
	}
	return 0;
}
