// 0.032

#include <stdio.h>
#include <math.h>

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
