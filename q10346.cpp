//2011-10-02 06:04:22
//0.008
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
