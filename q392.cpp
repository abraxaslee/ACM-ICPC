//q392.cpp - 2011/11/11
//accepted at 
//run time = 0.176c
#include <stdio.h>

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q392.in", "r", stdin);
	freopen("q392.out", "w", stdout);
	#endif

	int coeff[9]; char buff[50];
	int i, adjust;
	while(gets(buff)!=NULL){
		sscanf(buff, "%d%d%d%d%d%d%d%d%d", &coeff[8], &coeff[7], &coeff[6], &coeff[5], &coeff[4], &coeff[3], &coeff[2], &coeff[1], &coeff[0]);
		i=8, adjust = 1;
		while(coeff[i] == 0)
			--i;

		if(i > 1){

			if(coeff[i] == -1)
				printf("-x^%d", i);
			else if(coeff[i] < -1)
				printf("-%dx^%d", -coeff[i], i);
			else if(coeff[i] == 1)
				printf("x^%d", i);
			else if(coeff[i] > 1)
				printf("%dx^%d", coeff[i], i);
			--i;
			adjust = 0;
		}

		if(i == 1 && adjust == 1){

			if(coeff[1] < -1)
				printf("-%dx", -coeff[i]);
			else if(coeff[i] == -1)
				printf("-x");
			else if(coeff[i] == 1)
				printf("x");
			else if(coeff[i] > 1)
				printf("%dx", coeff[i]);
			--i;
			adjust = 0;
		}

		if(i == 0 && adjust == 1 ){

			if(coeff[0] < 0)
				printf("-%d\n", -coeff[0]);
			else if(coeff[0] == 0)
				putchar(10);
			else if(coeff[0] > 0)
				printf("%d\n", coeff[i]);

			continue;
		}

		if( i == -1){
			puts("0");
			continue;
		}
		while( i > 1){

			if(coeff[i] < -1)
				printf(" - %dx^%d", -coeff[i], i);
			else if(coeff[i] == -1)
				printf(" - x^%d", i);
			else if(coeff[i] == 1)
				printf(" + x^%d", i);
			else if(coeff[i] > 1)
				printf(" + %dx^%d", coeff[i], i);

			--i;
		}
		if(i==1){
			if(coeff[1] < -1)
				printf(" - %dx", -coeff[i]);
			else if(coeff[1] == -1)
				printf(" - x");
			else if(coeff[1] == 1)
				printf(" + x");
			else if(coeff[1] > 1)
				printf(" + %dx", coeff[i]);
			--i;
		}

		if(i==0){
			if(coeff[0] < 0)
				printf(" - %d", -coeff[0]);
			else if(coeff[0] > 0)
				printf(" + %d", coeff[0]);
		}
		putchar(10);
	}
	return 0;
}
