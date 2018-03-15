// 0.004

#include <stdio.h>

int main(){
	
	int n, k, smoked, reminder;
	while(scanf("%d %d", &n, &k)==2){
		smoked = n;
		while(n>=k){
		reminder = n%k;
		n = n/k;
		smoked += n;
		n += reminder;
		}
		printf("%d\n", smoked);
	}
	return 0;
}

