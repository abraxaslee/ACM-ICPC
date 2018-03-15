//q11661.cpp - 2011/09/13
//accepted at 2011-09-24 14:25:06
//run time = 0.096
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int caseNum;
	caseStart:
	scanf("%d", &caseNum);
	if(caseNum==0){
		return 0;
	}
	getchar();
	char c;
	bool foundZ = false, foundR = false, foundD = false;
	int recentR = 0;
	int recordDistance = 2000001;

	// 68 = D ,82 =R, 90=Z
	while((c=getchar())!='\n'){
		if(!foundZ){
			recentR += 1;
			if(c==90){
				recordDistance = 0;
				foundZ = true;
			}
			if(c==68){
				if(foundR){
					recordDistance = min(recordDistance,recentR);
					foundR = false;
				}
				recentR = 0;
				foundD = true;
			}
			if(c==82){
				if(foundD){
					recordDistance = min(recordDistance,recentR);
					foundD = false;
				}
				recentR = 0;
				foundR = true;
			}
		}
	}
	printf("%d\n", recordDistance);


	goto caseStart;
	return 0;
}
