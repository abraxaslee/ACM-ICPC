//q484.cpp - 2011/12/31
//accepted at 
//run time = 0.004
#include <stdio.h>

int nonegative[65536];
int negative[63357];
int output[10005];
int top;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q484.in", "r", stdin);
	freopen("q484.out", "w", stdout);
	#endif

	int input;
	while(scanf("%d", &input)!=EOF){
		if(input < 0){
			if(negative[-input]++ == 0)
				output[top++] = input;
		}else{
			if(nonegative[input]++ == 0)
				output[top++] = input;
		}
	}

	for(input=0; input<top; input++)
		printf("%d %d\n", output[input],  output[input]<0? negative[-output[input]]: nonegative[output[input]]);

	return 0;
}
