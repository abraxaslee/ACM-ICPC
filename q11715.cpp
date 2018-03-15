//q11715.cpp - 2011/12/10
//accepted at 
//run time = 0.004
#include <stdio.h>
#include <math.h>

int main(){
	
	int quest, current = 0;
	double u, v, a, s, t;
	while(scanf("%d", &quest) == 1){
		if(quest == 0)	break;

		if(quest == 1){
			scanf("%lf%lf%lf", &u, &v, &t);
			s = (u+v)*t/2;
			a = (v - u)/t;
			printf("Case %d: %.3lf %.3lf\n", ++current, s, a);
		}else if(quest == 2){
			scanf("%lf%lf%lf", &u, &v, &a);
			t = (v - u)/a;
			s = (u+v)*t/2;
			printf("Case %d: %.3lf %.3lf\n", ++current, s, t);
		}else if(quest == 3){
			scanf("%lf%lf%lf", &u, &a, &s);
			v = sqrt(2*a*s + u*u);
			t = (v - u)/a;
			printf("Case %d: %.3lf %.3lf\n", ++current, v, t);
		}else if(quest == 4){
			scanf("%lf%lf%lf", &v, &a, &s);
			u = sqrt(v*v - 2*a*s);
			t = (v - u)/a;
			printf("Case %d: %.3lf %.3lf\n", ++current, u, t);
		}
	}
	return 0;
}
