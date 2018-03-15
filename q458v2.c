// 0.020
#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q458.in", "r", stdin);
	freopen("q458.out", "w", stdout);
	#endif

	int c;
	while((c=getchar())!=EOF){
		if(c==10){
			putchar(10);
		}else{
			putchar(c-7);
		}
	}
	return 0;
}
