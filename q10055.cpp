//q10055.cpp - 2011/09/08
//10055 - Hashmat the Brave Warrior
//accepted at 2011-09-08 04:11:00
//run time = 0.060
#include <stdio.h>
using namespace std;

int main(){
	unsigned long teamA, teamB;
	while(scanf(" %ld %ld", &teamA, &teamB)!=EOF){
		if(teamA>teamB){
			printf("%ld\n", teamA - teamB);
		}else{
			printf("%ld\n", teamB - teamA);
		}
	}
	return 0;
}
