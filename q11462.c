// 0.540
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11462.in", "r", stdin);
	freopen("q11462.out", "w", stdout);
	#endif

	int n, i, j, tmp;
	while(scanf("%d", &n)!=EOF && n >0){
		int age[100] = {};
		int once = 0;
		for(i=0;i<n;i++){
			scanf("%d", &tmp);
			age[tmp-1] += 1;
		}
		for(i = 0,j = 0;i<n;j++){
			while(age[j]-- >0){
				if(once == 1){
					printf(" %d", j+1);
				}else{
					printf("%d", j+1);
					once = 1;
				}
				i++;
			}
		}
		putchar(10);
	}
	return 0;
}
