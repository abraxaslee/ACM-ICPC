//q839.cpp - 2011/12/11
//accepted at 
//run time = 0.060
#include <stdio.h>

int balance(){
	int WL, DL, WR, DR;
	scanf("%d%d%d%d", &WL, &DL, &WR, &DR);
	if(WL == 0)
		WL = balance();
	if(WR == 0)
		WR = balance();

	if(WL < 0 || WR < 0)
		return -1;

	if(WL * DL == WR * DR)
		return WL + WR;

	return -1;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q839.in", "r", stdin);
	freopen("q839.out", "w", stdout);
	#endif

	int caseNum, once = 0;
	scanf("%d", &caseNum); getchar();
	while(caseNum--){
		getchar();

		if(once)
			putchar(10);

		if(balance() == -1)
			puts("NO");
		else
			puts("YES");

		once = 1;
	}
	return 0;
}
