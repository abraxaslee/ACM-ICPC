//q311.cpp - 2011/11/24
//accepted at 
//run time = 
#include <stdio.h>

int min(int A, int B){
	return A<B ? A : B;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q311.in", "r", stdin);
	freopen("q311.out", "w", stdout);
	#endif

	int box[6], fill;
	long long int output;
	while(scanf("%d%d%d%d%d%d", &box[0], &box[1], &box[2], &box[3], &box[4], &box[5])){

			if(box[0] + box[1] + box[2] + box[3] + box[4] + box[5] == 0)
				break;

			fill = min(box[4], box[0]/11);
			box[0] -= fill * 11;
			box[4] -= fill;
			box[5] += fill;



			printf("%lld\n", output);
	}
	return 0;
}
