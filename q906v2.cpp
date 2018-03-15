//q906v2.cpp - 2011/11/13
//accepted at 
//run time = 0.016
#include <stdio.h>
#include <math.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q906.in", "r", stdin);
	freopen("q906.out", "w", stdout);
	#endif

	int a, b, c, d;
	double n;

	while(scanf("%d %d %lf", &a, &b, &n)!=EOF){
		d = ceil(1/(b*n));
		c = floor((a*d + b*d*n)/b);

		while (c*b <= a*d) {
			d++;
			c = floor((a*d + b*d*n)/b);
		}
		printf("%d %d\n", c, d);
	}
	return 0;
}
