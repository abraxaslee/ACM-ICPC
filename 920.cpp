//2012/02/24
//920.cpp
//Run time: 0.008

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct POINT{ double x, y; } p[1000];
int top;
const int szof = sizeof(POINT);

int cmp(const void *i, const void *j){
	return (*(POINT *)j).x - (*(POINT *)i).x;
}

double length(double x, double y){
	return sqrt(x*x + y*y);
}

double solve(){
	double result = 0.0, m, nx, temp;
	int i, max;
	max = p[0].y;
	for(i = 1; i < top; ++i)
		if(p[i].y > p[max].y){
			m = (p[i].y - p[i-1].y)/(p[i].x - p[i-1].x);
			temp = p[i].y - p[max].y;
			nx = p[i].x - temp / m;
			result += length(nx-p[i].x, temp);
			max = i;
		}

	return result;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("920.in", "r", stdin);
	freopen("920.out", "w", stdout);
	#endif

	int testCase, i;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d", &top);
		for(i=0; i<top; ++i)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		qsort(p, top, szof, cmp);
		printf("%.2lf\n", solve());
	}
	return 0;
}
