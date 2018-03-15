//2011-10-02 05:39:29
//0.076
#include <stdio.h>

int max(int numA, int numB){
	if(numA>numB){
		return numA;
	}
	return numB;
}

inline int min(int numA, int numB){
	if(numA<numB){
		return numA;
	}
	return numB;
}

int main(){
	
	int caseNum;
	scanf("%d", &caseNum);
	while(caseNum-- >0){
		int L, n;
		scanf("%d %d", &L, &n);
		int minT = 0, maxT = 0, temp = 0;
		while(n-- >0){
			scanf("%d", &temp);
			minT = max(minT, min(temp,L-temp));
			maxT = max(maxT, max(temp,L-temp));
		}
		printf("%d %d\n", minT, maxT);
	}

	return 0;
}
