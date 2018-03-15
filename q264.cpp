//q264.cpp - 2011/12/28
//accepted at 
//run time = 
#include <stdio.h>

int AP[4473];
int low, high, mid, input, ans[2], bRes;

void build_sum(){
	int i;
	for(i=1; i<4473; ++i)
		AP[i] = (1+i) *i/2;
	return;
}

int binarySearch(int search, int data[]){
	low = 1; high = 4473;

	while(low<=high){

		mid = (low + high)/2;

		if(data[mid] == search)
			return mid;
		else if(data[mid] > search)
			high = mid-1;
		else if(data[mid] < search)
			low = mid+1;
	}

	return -mid;
}

void solve(){
	bRes = binarySearch(input, AP);

	if(bRes < 0){
		bRes = -bRes;
		if(AP[bRes] < input)
			bRes++;

		ans[0] = bRes - (AP[bRes]-input);
		ans[1] = bRes - ans[0] + 1;
		if(bRes % 2 == 0)
			printf("%d/%d\n", ans[0], ans[1]);
		else
			printf("%d/%d\n", ans[1], ans[0]);
	}else{
		if(bRes % 2 == 0)
			printf("%d/1\n", bRes);
		else
			printf("1/%d\n", bRes);
	}
	return;
}

int main(){

	build_sum();
	while(scanf("%d", &input)!=EOF){
		printf("TERM %d IS ", input);
		solve();
	}
	return 0;
}
