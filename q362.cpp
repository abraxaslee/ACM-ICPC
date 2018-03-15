//q362.cpp - 2011/12/12
//accepted at 
//run time = 0.148
#include <stdio.h>

int getceil(double x){
	 if( x==(int)x || (x<0.0) )
		 return (int)x;
	return (int)(x+1);
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q362.in", "r", stdin);
	freopen("q362.out", "w", stdout);
	#endif

	int current = 0, tmp, i, sec, totalByte, perFive;
	double dtmp;
	while(scanf("%d", &totalByte)!=EOF){
		if(totalByte == 0)	break;
		printf("Output for data set %d, %d bytes:\n", ++current, totalByte);
		sec = perFive = i = 0;
		while(totalByte){
				scanf("%d", &tmp);
				totalByte -= tmp;
				perFive += tmp;
				++sec, ++i;
			if(i == 5){
				if(perFive){
					printf("   Time remaining: %d seconds\n", getceil((double)5.0*totalByte/perFive));
				}else
					puts("   Time remaining: stalled");
				perFive = i = 0;
			}
		}
		printf("Total time: %d seconds\n\n", sec);
	}
	return 0;
}
