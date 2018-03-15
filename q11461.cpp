//q11461.cpp - 2011/11/25
//accepted at 
//run time = 0.016
#include <stdio.h>

int cube[500];
int top;

void build_cube(){
	int i;
	for(i=1;i<317;++i)
		cube[top++] = i*i;
	return;
}

int linear_search(int a, int b){
	int i, result = 0;
	for(i=0; i<top ;i++){
		if(a <= cube[i] && cube[i] <= b)
			result += 1;
		else if(cube[i] > b)
			break;
	}
	return result;
}
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11461.in", "r", stdin);
	freopen("q11461.out", "w", stdout);
	#endif

	build_cube();
	int inputA, inputB;
	while(scanf("%d%d", &inputA, &inputB)!=EOF){
		if(inputA + inputB == 0)	break;
		printf("%d\n", linear_search(inputA,inputB));
	}
	return 0;
}
