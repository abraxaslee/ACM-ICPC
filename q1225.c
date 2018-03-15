//2011-10-05 15:38:14
//0.004
#include <stdio.h>

int main(){

	int caseNum = 0, N, buffer, i;
	scanf("%d", &caseNum);
	while(caseNum-- >0){
		int digits[10] = {};
		scanf("%d", &N);
		for(i=1;i<=N;i++){
			buffer = i;
			while(buffer>0){
			digits[buffer%10] += 1;
			buffer /= 10;
			}
		}
		printf("%d %d %d %d %d %d %d %d %d %d\n", digits[0], digits[1], digits[2], digits[3], digits[4], digits[5], digits[6], digits[7], digits[8], digits[9]);
	}
	return 0;
}
