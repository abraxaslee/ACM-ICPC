//q138.cpp - 2011/10/08
//accepted at 
//run time = -----
#include <stdio.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q138.out", "w", stdout);
	#endif

	struct Street{
		int k;
		int n;
	} street[10] ={};

	double left = 0, right = 1;
	int i = 1, j, n = 0;
	bool found[100000] = {};
	while(n<10){
		left += i;
		for(j= i+2 , right = 0;right<left;j++){
			right += j;
		}
		if(left == right){
			//printf("left = right\n%d = %d\n" , left, right);
			printf("%d %d\n", i, j-1);
			found[i] = true;
			n += 1;
			}
		i += 1;
	}
	return 0;
}
