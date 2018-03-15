//q906.cpp - 2011/11/12
//accepted at 
//run time = TLE
#include <stdio.h>

unsigned int binarySearch(unsigned int low, unsigned int high, long double denominator, long double error, double original){
	unsigned int mid, past = -1;
	long double fraction;

	while(low<high){
		past = mid;
		mid = (high + low)/2;
		if(mid==past)
			break;

		fraction = mid / denominator;

		//printf("fraction %.7lf, original %.7lf, error %.7lf; mid %u, low %u, high %u.\n", fraction, original, error, mid, low, high);
		if(fraction > original && (fraction - original) * error <= 1)
			return mid;
		else if(fraction < original)
			low = mid;
		else if(fraction > original)
			high = mid;
	}

	return -1;
}

void swap(double &a, double &b){
	double tmp = a;
	a = b;
	b = tmp;
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q906.in", "r", stdin);
	freopen("q906.out", "w", stdout);
	#endif

	double a, b, error, i;
	unsigned int tmp, switched;
	while(scanf("%lf%lf%lf", &a, &b, &error)==3){
		switched = 0;
		if( a > b){
			swap(a, b);
			switched = 1;
		}
		i = 0;
		while(true){
			++i;
			tmp = binarySearch(0, i, i, 1/error, a/b);
			if( tmp != -1){
				if(switched == 0)
					printf("%u %.0lf\n", tmp, i);
				else
					printf("%.0lf %u\n", i, tmp);
				break;
			}
		}
	}

	return 0;
}
