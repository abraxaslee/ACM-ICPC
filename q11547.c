// 0.004
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11547.in", "r", stdin);
	freopen("q11547.out", "w", stdout);
	#endif

	int caseNum, n;
	scanf("%d", &caseNum);
	while(caseNum-- >0){
		scanf("%d", &n);

		n = (315 * n) + 36962;
		n /= 10;
		n %= 10;
		if(n<0){
			n *= -1;
		}
		printf("%d\n", n);
	}
	return 0;
}
