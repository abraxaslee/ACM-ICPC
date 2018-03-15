//Q913: Joana and the Odd Numbers
//accepted at 2011-09-01 13:03:34
//run time = 0.008

#include <stdio.h>
int main(){
	long long row = 0;
	long long lastNum = 0;
	while(scanf("%lld", &row)!=EOF){
		lastNum = (1+row)/2;
		lastNum *= lastNum;
		lastNum = 2*(lastNum-1)+1;
		printf("%lld\n", 3*lastNum-6);
	}
	return 0;
}
