//q11650.cpp - 2011/12/24
//accepted at 
//run time = 0.008
#include <stdio.h>

int main(){

	#ifndef ONLINE_JUDGE
	freopen("q11650.in", "r", stdin);
	freopen("q11650.out", "w", stdout);
	#endif

	int i, HH, MM, caseNum;
	int hours[13], mins[61];

	hours[0] = hours[12] = 12;
	for(i=1; i<12; ++i){
		hours[i] = 12-i;
	}
	mins[0] = mins[60] = 0;
	for(i=1; i<60; ++i)
		mins[i] = 60-i;


	scanf("%d", &caseNum);
	while(caseNum--){
		scanf("%d:%d", &HH, &MM);
		if(MM == 0)
			printf("%02d:%02d\n", hours[HH], mins[MM]);
		else
			printf("%02d:%02d\n", (hours[HH]-1 == 0)?12 : hours[HH]-1, mins[MM]);
	}

	return 0;
}
