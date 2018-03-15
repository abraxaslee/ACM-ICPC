//q10110.cpp - 2011/10/05
//accepted at 
//run time = 0.044


//just find perfect squre number... if it is, then it switch on at last
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	double dN;
	unsigned int iN;
	while(scanf("%lf", &dN)!=EOF){
		if(dN==0){
			break;
		}
		dN = pow(dN,0.5);
		iN = (unsigned int)dN;
		if((dN-iN)==0){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
	return 0;
}
