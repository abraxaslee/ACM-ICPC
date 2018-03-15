//Q579:ClockHands
//q579.cpp - 2011/09/01
//accepted at 2011-09-01 08:40:52
//run time = 0.036

#include <stdio.h>
using namespace std;

int main(){
	int HR, MIN;
	float resANG;
	while(scanf("%d:%d", &HR, &MIN)!=EOF){
		if(HR==0&&MIN==0){break;}
		if((resANG = HR*30 - MIN*5.5)<0){
			resANG = -resANG;
		}
		if(resANG>180){resANG=360-resANG;}
		printf("%.3f\n", resANG);
	}
	return 0;
}
