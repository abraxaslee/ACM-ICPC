//q11839.cpp - 2011/12/17
//accepted at 
//run time = 0.008
#include <stdio.h>
char tag[5] = { 'A', 'B', 'C', 'D', 'E' };
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q11839.in", "r", stdin);
	freopen("q11839.out", "w", stdout);
	#endif
	int labelNum, tmp, i, total;
	char label;

	while(scanf("%d", &labelNum)!=EOF){
		if(labelNum == 0)	break;
		while(labelNum--){
			total = 0;
			for(i=0; i<5; ++i){
				scanf("%d", &tmp);
				if(tmp <= 127){
					label = tag[i];
					total += 1;
				}
			}
			if(total == 1)
				putchar(label);
			else
				putchar('*');

			putchar(10);
		}
	}
	return 0;
}
