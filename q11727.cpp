//q11727.cpp - 2011/10/11
//accepted at 2011/10/11
//run time = 0.000
#include <stdio.h>
using namespace std;

int salary[3] = {};
int top = 0;

void sort(int inputNum){
	int i;
	for(i = top-1; i >= 0 && salary[i] > inputNum; i--){
		salary[i+1] = salary[i];
	}
	i += 1;
	salary[i] = inputNum;
	top += 1;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11727.in", "r", stdin);
	freopen("q11727.out", "w", stdout);
	#endif

	int caseNum, currentCase = 0, tmp;
	scanf("%d", &caseNum);

	while(caseNum-- > 0){
		top = 0;
		for(int j=0;j<3;j++){
			scanf("%d", &tmp);
			sort(tmp);
		}
		printf("Case %d: %d\n", ++currentCase, salary[1]);
	}
	return 0;
}
