//q661.cpp - 2011/10/05
//accepted at 
//run time = 0.012
#include <stdio.h>
using namespace std;

inline int max(int inputNum, int maxNum){
	if(inputNum>maxNum){
		return inputNum;
	}
	return maxNum;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("q661.in", "r", stdin);
	freopen("q661.out", "w", stdout);
	#endif
	int n, m, c, caseNum = 0;
	while((scanf("%d %d %d", &n, &m, &c)!=EOF)&&n+m+c>0){
		caseNum = caseNum + 1;
		int machine[20] = {};
		bool power[20] = {};
		int amp = 0;
		int maxAmp = 0;

		//n line for  nth machine
		for(int i=0;i<n;i++){
			scanf("%d", &machine[i]);
		}

		//m line for mth command (switch on or off)
		int i_temp;
		bool fuseBlown = false;
		while(m-- >0){
			scanf("%d", &i_temp);
			i_temp -= 1;
			if(fuseBlown == false){
				if(power[i_temp] == true){
					//printf("turn off %d : %d - %d\n", i_temp, amp, machine[i_temp]);
					amp -= machine[i_temp];
					power[i_temp] = false;
				}else{
					//printf("turn on %d : %d + %d\n", i_temp, amp, machine[i_temp]);
					amp += machine[i_temp];
					if(amp > c){
						fuseBlown = true;
						continue;
					}
					maxAmp = max(amp, maxAmp);
					power[i_temp] = true;
				}
			}
		}
		printf("Sequence %d\n", caseNum);
		if(fuseBlown == true){
			printf("Fuse was blown.\n");
		}else{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", maxAmp);
		}
		putchar(10);
	}
	return 0;
}
