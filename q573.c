//q573.cpp - 2011/10/02
//accepted at 
//run time = 0.004
#include <stdio.h>

int main(){

	double H, U, D ,F;
	while(scanf("%lf %lf %lf %lf", &H, &U, &D, &F)!=EOF){
		if((H+U+D+F)==0){
			break;
		}

		double height = 0, fatigue = U * (F/100);
		int day = 0;

		while(1){
			day += 1;
			height = height + U;
			if(height>H){
				printf("success on day %d\n", day);
				break;
			}
			height = height - D;
			if(height<0){
				printf("failure on day %d\n", day);
				break;
			}
			U -= fatigue;
			if(U<0){
				U = 0;
			}
		}

	}
	return 0;
}
