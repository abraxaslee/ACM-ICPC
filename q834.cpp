//q834.cpp - 2011/11/12
//accepted at 
//run time = 0.004 c
#include <stdio.h>

int ans[1000];
int top;

void solve(int a, int b){
	if(a==1 || b ==0){
		return;
	}
	ans[top++] = a/b;
	solve(b,(a-(a/b)*b));
	return;
}


int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q834.in", "r", stdin);
	freopen("q834.out", "w", stdout);
	#endif

	int a, b, i;
	while(scanf("%d%d", &a, &b)!=EOF){
		top = 0, i = 1;
		if(a == 1){
			printf("[0;%d]\n", b);
		}else{
			solve(a,b);
			printf("[%d", ans[0]);
			if(i<top){
				putchar(';');
				while( i < top-1)
					printf("%d,", ans[i++]);
				if(i<top)
					printf("%d", ans[top-1]);
			}
			puts("]");
		}
	}
	return 0;
}
