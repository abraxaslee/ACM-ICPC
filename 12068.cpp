//2012/02/26
//12068.cpp
//Run time: 0.004

#include <stdio.h>

typedef struct rational{
	unsigned long long int up, down;
} fraction;

int gcd(unsigned long long int x,unsigned long long int y){
	if( y == 0 )	return x;
	return gcd( y, x % y);
}

void simplify(fraction *f){
	int GCD;
	for(GCD = gcd(f->up, f->down); GCD > 1; GCD = gcd(f->up, f->down)){
		f->up /= GCD;
		f->down /= GCD;
	}
}

fraction add(fraction *x, fraction *y){
	fraction result;
	result.up = x->up * y->down + x->down * y->up;
	result.down = x->down * y->down;
	simplify(&result);
	return result;
}

fraction divide(fraction *x, fraction *y){
	fraction result;
	result.up = x->up * y->down;
	result.down = x->down * y->up;
	simplify(&result);
	return result;
}

int caseNum;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("12068.in", "r", stdin);
	freopen("12068.out", "w", stdout);
	#endif

	fraction ans, sum, temp;
	unsigned long long int N;
	int i, testCase;
	scanf("%d", &testCase);

	while(testCase--){
		scanf("%llu", &N);
		ans.up = N, ans.down = 1;
		sum.up = 0, temp.up = sum.down = 1;

		for(i=0; i<N; ++i){
			scanf("%llu", &temp.down);
			sum = add(&sum, &temp);
		}
		ans = divide(&ans, &sum);
		printf("Case %d: %llu/%llu\n", ++caseNum, ans.up, ans.down);
	}
	return 0;
}
