//Q488: Triangle Wave
//q488.cpp - 2011/08/27
//accepted at 2011-08-28 08:17:54
//run time = 0.428

#include <stdio.h>
using namespace std;

void outWave(int amp);

int main(){
	int num, amp, freq;
	while(scanf("%d\n" ,&num)!=EOF){
		while(num>0){
		scanf("%d\n%d", &amp, &freq);
			while(freq>0){
				outWave(amp);
				freq--;
				if(freq!=0){printf("\n");}
			}
			num--;
			if(num!=0){printf("\n");}
		}
	}
	return 0;
}

void outWave(int amp){
	bool flagA = false;
	for(int i=1;(flagA)?i>0:i<=amp;(flagA)?i--:i++){
		for(int j=1;j<=i;j++){
			printf("%d", i);
			if(j==i){printf("\n");}
		}
		if(i==amp){flagA = true;}
	}
	return;
}
