//q11877.cpp - 2011/09/18
//accepted at 2011-09-18 06:56:03
//run time = 0.008
#include <stdio.h>
using namespace std;

int main(){
	int n;
	while( scanf("%d", &n) && n ){
		int total = 0;
		while(n>1){
			if(n==2){ total++; break;}
			total += n/3;
			n = n%3 + n/3;
		}
		printf("%d\n", total);
	}
	return 0;
}
